#include "pch.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Events/Events.h"

namespace Magma
{
	void WindowsWindowKeyPressedHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		switch (action)
		{
		case GLFW_PRESS:
			KeyPressedDispatcher.dispatch(0, { key, false });
		case GLFW_REPEAT:
			KeyPressedDispatcher.dispatch(0, { key, true });
		case GLFW_RELEASE:
			KeyReleasedDispatcher.dispatch(0, { key });
		}
	}

	void WindowsWindowCloseHandler(GLFWwindow* window)
	{
		WindowCloseDispatcher.dispatch(0, {});
	}

	WindowsWindow::WindowsWindow(const char* title, const int width, const int height)
		: Window()
	{
		MG_CORE_ASSERT(glfwInit(), "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
		MG_CORE_ASSERT(m_Window, "Failed to initialize the Window");

		glfwMakeContextCurrent(m_Window);
		MG_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to intialize Glad");

		glfwSetKeyCallback(m_Window, WindowsWindowKeyPressedHandler);
		glfwSetWindowCloseCallback(m_Window, WindowsWindowCloseHandler);

		// Initializing ImGui
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 330");

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	WindowsWindow::~WindowsWindow()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwTerminate();
	}

	void WindowsWindow::Update()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(m_Window);
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}
}