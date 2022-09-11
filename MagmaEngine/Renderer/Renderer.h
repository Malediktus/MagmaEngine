#pragma once

#include "pch.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"

namespace Magma
{
	class Renderer
	{
	public:
		static void Init();
		static void BeginFrame();
		static void EndFrame();

		static void DrawQuad();

	private:
		static Shader shader;
		static VertexBuffer vertexBuffer;
		static IndexBuffer indexBuffer;
	};
}