#pragma once

#include <string>
#include <stb/stb_image.h>
#include <glad/glad.h>

namespace Magma
{
	GLuint LoadTexture(const std::string& path);
}