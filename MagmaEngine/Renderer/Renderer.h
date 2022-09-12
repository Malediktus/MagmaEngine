#pragma once

#include "pch.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Magma
{
	class Renderer
	{
	public:
		static void Init();
		static void BeginFrame();
		static void EndFrame();

		static void DrawQuad(glm::mat4 transform, glm::vec4 color, GLuint texture);

	private:
		static Shader m_Shader;
		static VertexBuffer m_VertexBuffer;
		static IndexBuffer m_IndexBuffer;
		static GLuint m_WhiteTexture;

		static int m_BufferOffset;
		static std::vector<uint32_t> m_IndexBufferData;
		static std::array<int, 31> m_TextureSlots;
	};
}