#pragma once

#include <eventpp/eventdispatcher.h>

namespace Magma
{
	struct WindowCloseEvent
	{
	};

	struct WindowResizeEvent
	{
		const int width, height;
	};

	struct KeyPressedEvent
	{
		const int keyCode;
		const bool Repeat;
	};

	struct KeyReleasedEvent
	{
		const int keyCode;
	};

	extern eventpp::EventDispatcher<int, void(WindowCloseEvent)> WindowCloseDispatcher;
	extern eventpp::EventDispatcher<int, void(WindowResizeEvent)> WindowResizeDispatcher;

	extern eventpp::EventDispatcher<int, void(KeyPressedEvent)> KeyPressedDispatcher;
	extern eventpp::EventDispatcher<int, void(KeyReleasedEvent)> KeyReleasedDispatcher;

	#define BIND_CLASS_FUNCTION_TO_EVENT(fn) std::bind(&fn, this, std::placeholders::_1)
}