#pragma once

#ifdef MG_PLATFORM_WINDOWS

#include "pch.h"
#include "API/Application.h"
#include "API/Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Magma
{
	class Input
	{
	public:
		static bool GetKey(int keycode)
		{
			auto window = static_cast<GLFWwindow*>(Application::Get()->GetWindow()->GetNativeWindow());
			auto state = glfwGetKey(window, keycode);
			return state == GLFW_PRESS || state == GLFW_REPEAT;
		}

		static bool GetMouseButton(int button)
		{
			auto window = static_cast<GLFWwindow*>(Application::Get()->GetWindow()->GetNativeWindow());
			auto state = glfwGetMouseButton(window, button);
			return state == GLFW_PRESS;
		}

		static std::pair<float, float> GetMousePosition()
		{
			auto window = static_cast<GLFWwindow*>(Application::Get()->GetWindow()->GetNativeWindow());
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);

			return { (float)xpos, (float)ypos };
		}

		static float GetMousePositionX()
		{
			auto [x, y] = GetMousePosition();
			return x;
		}

		static float GetMousePositionY()
		{
			auto [x, y] = GetMousePosition();
			return y;
		}
	};
}

#endif