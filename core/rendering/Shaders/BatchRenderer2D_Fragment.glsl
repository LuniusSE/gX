R"(
#version 460 core

out vec4 _Colour;

in vec4 _Tint;
in vec2 _TexCoord;
in vec2 _Tiling;
in float _TextureId;

uniform sampler2D uTextures[32];

void main()
{
    _Colour = texture(uTextures[int(_TextureId)], _TexCoord * _Tiling) * _Tint;
}
)"