#pragma once

#include "API/Window.h"
#include "Events/Events.h"

namespace Magma
{
	class Application
	{
	public:
		static Application* Get() { return Instance; }
		std::shared_ptr<Window> GetWindow() { return m_Window; }

		virtual void Start() = 0;
		virtual void Update() = 0;

		void OnWindowClose(WindowCloseEvent e);

		void Run();

	private:
		bool m_Running;
		std::shared_ptr<Window> m_Window;
		static Application* Instance;
	};

	// Needs to be defined in Client
	extern Application* Initialize();
}