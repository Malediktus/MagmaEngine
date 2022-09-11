#pragma once

#include "pch.h"

namespace Magma
{
	class VertexBuffer
	{
	public:
		VertexBuffer() = default;
		~VertexBuffer();

		bool Load(void* data, uint32_t numVertices);
		void Bind();
		void Unbind();

	private:
		GLuint bufferId;
		GLuint vao;
	};
}