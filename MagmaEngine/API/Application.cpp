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

		const uint8_t* version = glGetString(GL_VERSION);
		MG_CORE_INFO("OpenGL version supported by this platform ({0}): ", (const char*)version);

		MG_CORE_INFO("Started MagmaEngine");
		Start();

		GLuint testTex = LoadTexture("../MagmaEngine/Resources/MagmaIcon.png");
		
		glm::vec3 position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 rotation = { 1.0f, 1.0f, 1.0f };
		glm::vec3 scale = { 0.18f, 0.32f, 0.0f };
		glm::vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f };
		float imguiColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			Update();

			ImGui::Begin("Logo Transform");

			ImGui::Text("Position");
			ImGui::SliderFloat("X:posX", &position.x, -1.0f, 1.0f);
			ImGui::SliderFloat("Y:posY", &position.y, -1.0f, 1.0f);
			ImGui::SliderFloat("Z:posZ", &position.z, -1.0f, 1.0f);

			ImGui::Text("Rotation");
			ImGui::SliderFloat("X:rotX", &rotation.x, -380.0f, 380.0f);
			ImGui::SliderFloat("Y:rotY", &rotation.y, -380.0f, 380.0f);
			ImGui::SliderFloat("Z:rotZ", &rotation.z, -380.0f, 380.0f);

			ImGui::Text("Scale");
			ImGui::SliderFloat("X:scaleX", &scale.x, -1.0f, 1.0f);
			ImGui::SliderFloat("Y:scaleY", &scale.y, -1.0f, 1.0f);
			ImGui::SliderFloat("Z:scaleZ", &scale.z, -1.0f, 1.0f);

			ImGui::Text("Color");
			ImGui::ColorPicker4("Color:color", imguiColor);

			ImGui::End();

			color.r = imguiColor[0];
			color.g = imguiColor[1];
			color.b = imguiColor[2];
			color.a = imguiColor[3];

			glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), scale);
			transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
			transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
			transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0, 0, 1));

			Renderer::BeginFrame();
			Renderer::DrawQuad(transform, color, testTex);
			Renderer::EndFrame();

			m_Window->Update();
		}

		Logger::Shutdown();
	}
}