#pragma once

#include <memory>

namespace Magma
{
	class Window
	{
	public:
		virtual void Update() = 0;
		virtual void* GetNativeWindow() const = 0;
		static std::shared_ptr<Window> Create(const char* title, const int width, const int height);
	};
}