#pragma once

#include "pch.h"

namespace Magma
{
	class Shader
	{
	public:
		Shader() = default;
		~Shader();

		bool Load(const char* vertFilename, const char* fragFilename); // true: success, false: error
		void Bind();
		void Unbind();

		void UploadIntArray(const char* name, int* data, int size);

	private:
		GLuint shaderProgram;
	};
}