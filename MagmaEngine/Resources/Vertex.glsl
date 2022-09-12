#version 330 core

layout (location = 0) in vec3 a_position;
layout (location = 1) in vec4 a_color;
layout (location = 2) in vec2 a_texCoord;
layout (location = 3) in float a_texIndex;

out vec4 v_color;
out vec2 v_texCoord;
out float v_texIndex;

void main()
{
	v_color = a_color;
	v_texCoord = a_texCoord;
	v_texIndex = a_texIndex;
	gl_Position = vec4(a_position, 1.0f);
}