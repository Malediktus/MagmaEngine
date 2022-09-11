#include "pch.h"
#include "Events/Events.h"

namespace Magma
{
	eventpp::EventDispatcher<int, void (WindowCloseEvent)> WindowCloseDispatcher;
	eventpp::EventDispatcher<int, void (WindowResizeEvent)> WindowResizeDispatcher;

	eventpp::EventDispatcher<int, void (KeyPressedEvent)> KeyPressedDispatcher;
	eventpp::EventDispatcher<int, void (KeyReleasedEvent)> KeyReleasedDispatcher;
}