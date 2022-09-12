#pragma once

#include "pch.h"

#include <glm/glm.hpp>

namespace Magma
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec4 Color;
		float TexCoords[2];
		float TexID;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer() = default;
		~VertexBuffer();

		bool Load(uint32_t numMaxVertices);
		bool Load(void* data, uint32_t numIndices);
		void Bind();
		void Unbind();

		GLuint GetID() { return bufferId; }

	private:
		GLuint bufferId;
		GLuint vao;
	};
}