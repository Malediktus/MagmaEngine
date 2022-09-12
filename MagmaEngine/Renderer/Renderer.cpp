#include "pch.h"
#include "Renderer/Renderer.h"

namespace Magma
{
	Shader Renderer::m_Shader;
	VertexBuffer Renderer::m_VertexBuffer;
	IndexBuffer Renderer::m_IndexBuffer;
	GLuint Renderer::m_WhiteTexture;
	int Renderer::m_BufferOffset;
	std::vector<uint32_t> Renderer::m_IndexBufferData;
	std::array<int, 31> Renderer::m_TextureSlots;

	void Renderer::Init()
	{
		m_Shader.Load("../MagmaEngine/Resources/Vertex.glsl", "../MagmaEngine/Resources/Fragment.glsl");

		m_VertexBuffer.Load(1000); // TODO: Optimaize max vertices
		m_VertexBuffer.Unbind();

		m_WhiteTexture = LoadTexture("../MagmaEngine/Resources/White.png");

		int samplers[32] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
		m_Shader.UploadIntArray("u_textures", samplers, 2);

		int maxTextureSlots;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureSlots);

		for (int i = 0; i < m_TextureSlots.max_size(); i++)
		{
			m_TextureSlots[i] = -1;
		}

		m_TextureSlots[0] = m_WhiteTexture;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_WhiteTexture);
	}

	void Renderer::BeginFrame()
	{
		m_IndexBufferData.clear();
		m_BufferOffset = 0;
		for (int i = 1; i < m_TextureSlots.max_size(); i++)
		{
			m_TextureSlots[i] = -1;
		}
	}

	void Renderer::EndFrame()
	{
		m_IndexBuffer.Load(m_IndexBufferData.data(), (uint32_t)m_IndexBufferData.size(), sizeof(m_IndexBufferData[0]));

		m_Shader.Bind();
		m_VertexBuffer.Bind();
		m_IndexBuffer.Bind();

		glDrawElements(GL_TRIANGLES, (uint32_t)m_IndexBufferData.size(), GL_UNSIGNED_INT, nullptr);

		m_IndexBuffer.Delete();
	}

	void Renderer::DrawQuad(glm::mat4 transform, glm::vec4 color, GLuint texture)
	{
		Vertex v0 = { transform * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), color, 0.0f, 0.0f, -1.0f };
		Vertex v1 = { transform * glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f), color, 1.0f, 0.0f, -1.0f };
		Vertex v2 = { transform * glm::vec4( 0.5f,  0.5f, 0.0f, 1.0f), color, 1.0f, 1.0f, -1.0f };
		Vertex v3 = { transform * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f), color, 0.0f, 1.0f, -1.0f };

		for (int i = 0; i < m_TextureSlots.max_size(); i++)
		{
			if (m_TextureSlots[i] == texture)
			{
				v0.TexID = (float)i;
				v1.TexID = (float)i;
				v2.TexID = (float)i;
				v3.TexID = (float)i;
				break;
			}
		}

		if (v0.TexID == -1)
		{
			for (int i = 0; i < m_TextureSlots.max_size(); i++)
			{
				if (m_TextureSlots[i] == -1)
				{
					v0.TexID = (float)i;
					v1.TexID = (float)i;
					v2.TexID = (float)i;
					v3.TexID = (float)i;

					m_TextureSlots[i] = texture;

					glActiveTexture(GL_TEXTURE0+i);
					glBindTexture(GL_TEXTURE_2D, texture);
					break;
				}
			}
		}

		if (v0.TexID == -1)
		{
			MG_CORE_ASSERT("out of texture units");
			// TODO: Start new batch
		}

		Vertex vertices[4] = { v0, v1, v2, v3 };
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer.GetID());
		glBufferSubData(GL_ARRAY_BUFFER, m_BufferOffset, sizeof(vertices), vertices);
		const int vertexCount = m_BufferOffset / sizeof(Vertex);
		m_IndexBufferData.push_back(0 + vertexCount);
		m_IndexBufferData.push_back(1 + vertexCount);
		m_IndexBufferData.push_back(2 + vertexCount);
		m_IndexBufferData.push_back(2 + vertexCount);
		m_IndexBufferData.push_back(3 + vertexCount);
		m_IndexBufferData.push_back(0 + vertexCount);
		m_BufferOffset += sizeof(Vertex) * 4;
	}
}