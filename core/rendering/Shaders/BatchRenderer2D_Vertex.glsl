R"(
#version 460 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Tint;
layout (location = 2) in vec2 TexCoord;

uniform mat4 uViewProjection;

out vec4 _Tint;
out vec2 _TexCoord;

void main()
{
    gl_Position = uViewProjection * vec4(Position, 1.0f);

    _TexCoord = TexCoord;
    _Tint = Tint;
}
)"