#include "pch.h"
#include "IndexBuffer.h"

namespace Magma
{
	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &bufferId);
	}

	bool IndexBuffer::Load(void* data, uint32_t numIndices, uint8_t elementSize)
	{
		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * elementSize, data, GL_STATIC_DRAW);
		return true;
	}

	void IndexBuffer::Delete()
	{
		if (bufferId)
			glDeleteBuffers(1, &bufferId);
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	}

	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}