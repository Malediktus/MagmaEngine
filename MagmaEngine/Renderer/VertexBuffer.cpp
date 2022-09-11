#include "pch.h"
#include "Renderer/VertexBuffer.h"

namespace Magma
{
	VertexBuffer::~VertexBuffer()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &bufferId);
	}

	bool VertexBuffer::Load(void* data, uint32_t numVertices)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(float), data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return true;
	}

	void VertexBuffer::Bind()
	{
		glBindVertexArray(vao);
	}

	void VertexBuffer::Unbind()
	{
		glBindVertexArray(0);
	}
}