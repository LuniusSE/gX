/*
// gX 2D Renderer API
*/

#include "rendering/Renderer2D.hpp"
#include "rendering/RenderCmd.hpp"
#include "rendering/Arrays.hpp"
#include "rendering/Buffers.hpp"
#include "rendering/Shaders.hpp"
#include "rendering/Textures.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <unordered_map>

_GX_BEGIN

constexpr uInt BatchedQuads     = 5000u;
constexpr uInt BatchedVertices  = BatchedQuads * 4u;
constexpr uInt BatchedIndices   = BatchedQuads * 6u;

constexpr uInt MaxTextures      = 32u;
constexpr uInt ReservedTextures = 1u;

/**
 * Reserved Textures
 * 	0u - Default White Texture
 **/

struct Vertex {
    Vec3 Position;
    Vec4 Tint;
    Vec2 TexCoord;
    Vec2 Tiling;
    float TextureId;
};

struct Scene {
    uInt elementCount = 0u;

    Reference<VertexArray> vertexArray;
    Reference<VertexBuffer> _vertexBuffer;
    Reference<ElementBuffer> _elementBuffer;
    
    Reference<Texture2D> defaultTexture;
    Reference<Shader> shader;

    Orthographic* projection;

    Vec4 defaultQuadVertices[4];
    Vertex* pQuadVertexBuffer;
    Vertex* pQuadVertexBufferPtr;

    int textureUniformSamplers[MaxTextures];
    Reference<Texture2D> textureSlots[MaxTextures];
    uInt textureIndex = ReservedTextures;
};

static Scene s_Scene;

void Renderer2D::Initialize()
{
    s_Scene.pQuadVertexBuffer = nullptr;
    s_Scene.pQuadVertexBufferPtr = nullptr;

    for (int i = 0; i < MaxTextures; i++)
        s_Scene.textureUniformSamplers[i] = i;

    s_Scene.defaultQuadVertices[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
    s_Scene.defaultQuadVertices[1] = {  0.5f, -0.5f, 0.0f, 1.0f };
    s_Scene.defaultQuadVertices[2] = {  0.5f,  0.5f, 0.0f, 1.0f };
    s_Scene.defaultQuadVertices[3] = { -0.5f,  0.5f, 0.0f, 1.0f };


    s_Scene.vertexArray = VertexArray::Create();

    /** Setup VertexBuffer **/
    s_Scene.pQuadVertexBuffer = (Vertex*)malloc(BatchedVertices * sizeof(Vertex));
    
    s_Scene._vertexBuffer = VertexBuffer::Create(BatchedVertices * sizeof(Vertex));
    s_Scene._vertexBuffer->SetLayout({
        Attribute::Float3, 
        Attribute::Float4, 
        Attribute::Float2, 
        Attribute::Float2, 
        Attribute::Float
    });
    s_Scene.vertexArray->AttachVertexBuffer(s_Scene._vertexBuffer);

    /** Setup ElementBuffer **/
    std::vector<Index> pIndices = std::vector<Index>(BatchedIndices, 0u);

    uInt uOffset = 0u;
    for (uInt i = 0; i < BatchedIndices; i += 6)
    {
        pIndices[i + 0u] = uOffset + 0u;
        pIndices[i + 1u] = uOffset + 1u;
        pIndices[i + 2u] = uOffset + 2u;

        pIndices[i + 3u] = uOffset + 2u;
        pIndices[i + 4u] = uOffset + 3u;
        pIndices[i + 5u] = uOffset + 0u;

        uOffset += 4u;
    }

    s_Scene._elementBuffer = ElementBuffer::Create(pIndices);
    s_Scene.vertexArray->AttachElementBuffer(s_Scene._elementBuffer);

    /** Setup Shaders **/

    /** Include BatchRenderer2D_Vertex.glsl as a RawString **/
    std::string VertexShader =
        #include "Shaders/BatchRenderer2D_Vertex.glsl"
    ;

    /** Include BatchRenderer2D_Fragment.glsl as a RawString **/
    std::string FragmentShader =
        #include "Shaders/BatchRenderer2D_Fragment.glsl"
    ;

    /** Create Shader **/
    s_Scene.shader = Shader::Create(VertexShader, FragmentShader);

    /** Create default White Texture **/
    uInt whiteTextureData = 0xffffffff;
    s_Scene.defaultTexture = Texture2D::Create({ 1, 1 }, &whiteTextureData);

    /** Set reserves **/
    s_Scene.textureSlots[0] = s_Scene.defaultTexture;
}

void Renderer2D::Shutdown()
{
    free(s_Scene.pQuadVertexBuffer);

    s_Scene.pQuadVertexBuffer = nullptr;
    s_Scene.pQuadVertexBufferPtr = nullptr;
}

void Renderer2D::StartBatch()
{
    s_Scene.textureIndex = ReservedTextures;

    s_Scene.elementCount = 0u;
    s_Scene.pQuadVertexBufferPtr = s_Scene.pQuadVertexBuffer;
}

void Renderer2D::NextBatch()
{
    Flush();
    StartBatch();
}

void Renderer2D::BeginScene(Orthographic& _Projection)
{
    s_Scene.projection = &_Projection;

    StartBatch();
}

void Renderer2D::EndScene()
{
    Size BufferUsageSize = ((uChar*)s_Scene.pQuadVertexBufferPtr - (uChar*)s_Scene.pQuadVertexBuffer);
    s_Scene._vertexBuffer->SetBufferData(s_Scene.pQuadVertexBuffer, BufferUsageSize);
    
    Flush();
}

void Renderer2D::Flush()
{
    if (s_Scene.elementCount == 0u)
        return;

    s_Scene.shader->Bind();
    s_Scene.shader->SetUniformIntArray("uTextures", 32, s_Scene.textureUniformSamplers);
    s_Scene.shader->SetUniformMat4("uViewProjection", *s_Scene.projection);

    for (uInt i = 0; i < s_Scene.textureIndex; i++)
    {
        s_Scene.textureSlots[i]->Bind(i);
    }

    RenderCmd::GetGraphicsAPI()->DrawIndexed(s_Scene.vertexArray, s_Scene.elementCount);
}

void Renderer2D::BuildQuad(const Mat4& Transform, const Vec2& _vTiling, const Vec4& _vColour, const Int& _nTextureIndex)
{
    if(s_Scene.elementCount >= BatchedIndices)
        NextBatch();

    s_Scene.pQuadVertexBufferPtr->Position = Transform * s_Scene.defaultQuadVertices[0];
    s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
    s_Scene.pQuadVertexBufferPtr->TexCoord = { 0.0f, 0.0f };
    s_Scene.pQuadVertexBufferPtr->Tiling = _vTiling;
    s_Scene.pQuadVertexBufferPtr->TextureId = _nTextureIndex;
    s_Scene.pQuadVertexBufferPtr++;

    s_Scene.pQuadVertexBufferPtr->Position = Transform * s_Scene.defaultQuadVertices[1];
    s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
    s_Scene.pQuadVertexBufferPtr->TexCoord = { 1.0f, 0.0f };
    s_Scene.pQuadVertexBufferPtr->Tiling = _vTiling;
    s_Scene.pQuadVertexBufferPtr->TextureId = _nTextureIndex;
    s_Scene.pQuadVertexBufferPtr++;

    s_Scene.pQuadVertexBufferPtr->Position = Transform * s_Scene.defaultQuadVertices[2];
    s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
    s_Scene.pQuadVertexBufferPtr->TexCoord = { 1.0f, 1.0f };
    s_Scene.pQuadVertexBufferPtr->Tiling = _vTiling;
    s_Scene.pQuadVertexBufferPtr->TextureId = _nTextureIndex;
    s_Scene.pQuadVertexBufferPtr++;

    s_Scene.pQuadVertexBufferPtr->Position = Transform * s_Scene.defaultQuadVertices[3];
    s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
    s_Scene.pQuadVertexBufferPtr->TexCoord = { 0.0f, 1.0f };
    s_Scene.pQuadVertexBufferPtr->Tiling = _vTiling;
    s_Scene.pQuadVertexBufferPtr->TextureId = _nTextureIndex;
    s_Scene.pQuadVertexBufferPtr++;

    s_Scene.elementCount += 6u;
}

void Renderer2D::RenderQuad(const Mat4& _mTransform, const Vec2& _vTiling, const Vec4& _vColour, Reference<Texture2D>& _pTexture)
{
    Int textureIndex = 0;

    for (Int i = 0; i < s_Scene.textureIndex; i++)
    {
        if (s_Scene.textureSlots[i]->GetProgram() == _pTexture->GetProgram())
        {
            textureIndex = i;
            break;
        }
    }

    if (textureIndex == 0)
    {
        textureIndex = s_Scene.textureIndex;
        s_Scene.textureSlots[textureIndex] = _pTexture;
        s_Scene.textureIndex++;
    }

    BuildQuad(_mTransform, _vTiling, _vColour, textureIndex);
}

_GX_END