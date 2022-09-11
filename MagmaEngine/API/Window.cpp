#include "pch.h"
#include "API/Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Magma
{
	std::shared_ptr<Window> Window::Create(const char* title, const int width, const int height)
	{
		if (Context::GetPlatform() == Platform::WINDOWS)
			return std::make_shared<WindowsWindow>(title, width, height);
	}
}