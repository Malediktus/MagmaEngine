#include "API/Window.h"

namespace Magma
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const char* title, const int width, const int height);
		~WindowsWindow();

		void Update() override;

		void* GetNativeWindow() const override;

	private:
		GLFWwindow* m_Window;
	};
}