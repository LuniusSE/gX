/*
// 2D Renderer
*/
#include "Renderer2D.hpp"
#include "Rendering.hpp"
#include "Arrays.hpp"
#include "Buffers.hpp"
#include "Shaders.hpp"
#include "Textures.hpp"

#include <vector>
#include <string>

_GX_BEGIN

constexpr uInt BatchedQuads 	= 5000;
constexpr uInt BatchedVertices 	= BatchedQuads * 4;
constexpr uInt BatchedIndices 	= BatchedQuads * 6;

struct Vertex
{
    Vec3 Position;
	Vec4 Tint;
	Vec2 TexCoord;
};

struct Scene
{
	Vertex defaultQuadVertices[4];
	Reference<VertexArray> vertexArray;
	Reference<VertexBuffer> _vertexBuffer;
	Reference<ElementBuffer> _elementBuffer;
	Reference<Shader> shader;
	Orthographic* projection;

	Vertex* pQuadVertexBuffer;
	Vertex* pQuadVertexBufferPtr;

	uInt indicesCount = 0u;
};

static Scene s_Scene;

/**
 * Renderer2D::Initialize Implementation
**/
void Renderer2D::Initialize()
{
	s_Scene.pQuadVertexBuffer = nullptr;
	s_Scene.pQuadVertexBufferPtr = nullptr;

	s_Scene.vertexArray = VertexArray::Create();

	s_Scene.pQuadVertexBuffer = (Vertex*)malloc(BatchedVertices * sizeof(Vertex));

	s_Scene._vertexBuffer = VertexBuffer::Create(BatchedVertices * sizeof(Vertex));
	s_Scene._vertexBuffer->SetLayout({ Attribute::Float3, Attribute::Float4, Attribute::Float2 });
	s_Scene.vertexArray->AttachVertexBuffer(s_Scene._vertexBuffer);

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

	std::string VertexShader =
		#include "Shaders/BatchRenderer2D_Vertex.glsl"
	;

	std::string FragmentShader =
		#include "Shaders/BatchRenderer2D_Fragment.glsl"
	;

	s_Scene.shader = Shader::Create(VertexShader, FragmentShader);
}

/**
 * Renderer2D::Shutdown Implementation
**/
void Renderer2D::Shutdown()
{
	free(s_Scene.pQuadVertexBuffer);

	s_Scene.pQuadVertexBuffer = nullptr;
	s_Scene.pQuadVertexBufferPtr = nullptr;
}

/**
 * Renderer2D::BeginScene Implementation
**/
void Renderer2D::BeginScene(Orthographic& _Projection)
{
	s_Scene.projection = &_Projection;

	s_Scene.indicesCount = 0u;
	s_Scene.pQuadVertexBufferPtr = s_Scene.pQuadVertexBuffer;
}

/**
 * Renderer2D::EndScene Implementation
**/
void Renderer2D::EndScene()
{
	Size BufferUsageSize = ((uChar*)s_Scene.pQuadVertexBufferPtr - (uChar*)s_Scene.pQuadVertexBuffer);
	s_Scene._vertexBuffer->SetBufferData(s_Scene.pQuadVertexBuffer, BufferUsageSize);
	
	Flush();
}

/**
 * Renderer2D::Flush Implementation
**/
void Renderer2D::Flush()
{
	s_Scene.shader->Bind();
	s_Scene.shader->SetUniformMat4("uViewProjection", *s_Scene.projection);

	Rendering::GetGraphicsAPI()->DrawIndexed(s_Scene.vertexArray, s_Scene.indicesCount);
}

/**
 * Renderer2D::RenderQuad Implementation
**/
void Renderer2D::RenderQuad(const Vec4& _vColour, const Vec3& _vSize, const Vec3& _vPosition)
{
	s_Scene.pQuadVertexBufferPtr->Position = _vPosition;
	s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
	s_Scene.pQuadVertexBufferPtr->TexCoord = { 0.0f, 0.0f };
	s_Scene.pQuadVertexBufferPtr++;

	s_Scene.pQuadVertexBufferPtr->Position = { _vPosition.x + _vSize.x, _vPosition.y, 0.f };
	s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
	s_Scene.pQuadVertexBufferPtr->TexCoord = { 1.0f, 0.0f };
	s_Scene.pQuadVertexBufferPtr++;

	s_Scene.pQuadVertexBufferPtr->Position = { _vPosition.x + _vSize.x, _vPosition.y + _vSize.y, 0.f };
	s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
	s_Scene.pQuadVertexBufferPtr->TexCoord = { 1.0f, 1.0f };
	s_Scene.pQuadVertexBufferPtr++;

	s_Scene.pQuadVertexBufferPtr->Position = { _vPosition.x, _vPosition.y + _vSize.y, 0.f };
	s_Scene.pQuadVertexBufferPtr->Tint = _vColour;
	s_Scene.pQuadVertexBufferPtr->TexCoord = { 0.0f, 1.0f };
	s_Scene.pQuadVertexBufferPtr++;

	s_Scene.indicesCount += 6u;
}

_GX_END