R"(
#version 460 core

out vec4 _Colour;

in vec4 _Tint;
in vec2 _TexCoord;

void main()
{
    _Colour = _Tint;
}
)"