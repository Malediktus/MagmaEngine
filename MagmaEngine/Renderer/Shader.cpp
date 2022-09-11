#include "pch.h"
#include "Renderer/Shader.h"

namespace Magma
{
	Shader::~Shader()
	{
		glDeleteProgram(shaderProgram);
	}

	bool Shader::Load(const char* vertFilename, const char* fragFilename)
	{
		// Loading the shader sources
		std::ifstream file(vertFilename);
		std::stringstream vertexContent;
		vertexContent << file.rdbuf();
		std::string vertexContentStr = vertexContent.str();
		const char* vertexShaderSource = vertexContentStr.c_str();

		std::ifstream file2(fragFilename);
		std::stringstream fragmentContent;
		fragmentContent << file2.rdbuf();
		std::string fragmentContentStr = fragmentContent.str();
		const char* fragmentShaderSource = fragmentContentStr.c_str();

		// Creating the vertex shader
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		// Check for errors
		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			MG_CORE_ASSERT(false, "ERROR::SHADER::VERTEX::COMPILATION_FAILED {0}", infoLog);
			return false;
		}

		// Creating the fragment shader
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		// Check for errors
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			MG_CORE_ASSERT(false, "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED {0}", infoLog);
			return false;
		}

		// Creating and linking the shader program
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		// Check for errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			MG_CORE_ASSERT(false, "ERROR::SHADER::PROGRAM::LINKING_FAILED {0}", infoLog);
			return false;
		}

		// Cleaning up
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return true;
	}

	void Shader::Bind()
	{
		glUseProgram(shaderProgram);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}
}