#include "pch.h"
#include "Renderer/Renderer.h"

namespace Magma
{
	Shader Renderer::shader;
	VertexBuffer Renderer::vertexBuffer;
	IndexBuffer Renderer::indexBuffer;

	void Renderer::Init()
	{
		shader.Load("../MagmaEngine/Resources/Vertex.glsl", "../MagmaEngine/Resources/Fragment.glsl");

		uint32_t verticesSize = 12;
		uint32_t indicesSize = 6;
		float vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
		};
		uint32_t indices[] = {
			0, 1, 2,
			1, 2, 3
		};

		vertexBuffer.Load(vertices, verticesSize);
		vertexBuffer.Unbind();
		indexBuffer.Load(indices, indicesSize, sizeof(indices[0]));
	}

	void Renderer::BeginFrame()
	{
	}

	void Renderer::EndFrame()
	{
	}

	void Renderer::DrawQuad()
	{
		shader.Bind();
		vertexBuffer.Bind();
		indexBuffer.Bind();
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, 6/*indicesSize*/, GL_UNSIGNED_INT, 0);
	}
}