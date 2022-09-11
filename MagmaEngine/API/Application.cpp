#include "pch.h"
#include "API/Application.h"
#include "Events/Input.h"
#include "Renderer/Renderer.h"

namespace Magma
{
	Application* Application::Instance = nullptr;

	void Application::OnWindowClose(WindowCloseEvent e)
	{
		m_Running = false;
	}

	void Application::Run()
	{
		Instance = this;
		m_Running = true;
		Context::Init();
		Logger::Init();
		m_Window = Window::Create("Magma Engine", 1792, 1008);
		WindowCloseDispatcher.appendListener(0, BIND_CLASS_FUNCTION_TO_EVENT(Application::OnWindowClose));
		Renderer::Init();

		MG_CORE_INFO("Started MagmaEngine");
		Start();
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			Update();

			Renderer::BeginFrame();
			Renderer::DrawQuad();
			Renderer::EndFrame();

			m_Window->Update();
		}

		Logger::Shutdown();
	}
}