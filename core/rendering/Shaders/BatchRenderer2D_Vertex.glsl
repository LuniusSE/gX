R"(
#version 460 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Tint;
layout (location = 2) in vec2 TexCoord;
layout (location = 3) in vec2 Tiling;
layout (location = 4) in float TextureId;

uniform mat4 uViewProjection;

out vec4 _Tint;
out vec2 _TexCoord;
out vec2 _Tiling;
out float _TextureId;

void main()
{
    gl_Position = uViewProjection * vec4(Position, 1.0f);

    _TextureId = TextureId;
    _Tiling = Tiling;
    _TexCoord = TexCoord;
    _Tint = Tint;
}
)"