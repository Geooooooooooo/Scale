#include "sl_pch.h"
#include "../../ScaleEngine-x64/src/Scale/Log.h"
#include "../../Libs/include/GLFW/glfw3.h"

#ifdef SL_WINDOWS_PLATFORM
#include "Window.h"

namespace Scale {
	static bool s_GLFWinited = false;

	Window::Window(const WindowProps& props = WindowProps()) {
		SL_CORE_INFO("Window::Window()");
		Init(props);
	}

	Window::~Window() {
		shutdown();
	}

	Window* Window::create(const WindowProps& props) {
		SL_CORE_INFO("Window* Window::create()");
		return new Window(props);
	}

	void Window::Init(const WindowProps& props) {
		m_Data.wd_Title = props.Title;
		m_Data.wd_Height = props.Height;
		m_Data.wd_Widht = props.Width;

		if (!s_GLFWinited) {
			int success = glfwInit();
			SL_CORE_ERROR(success);

			s_GLFWinited = true;
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.wd_Title.c_str(), 0, 0);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVerticalSync(true);

		SL_CORE_INFO("Creating a window {0} ({1}, {2})", props.Title, props.Width, props.Height);
	}

	void Window::shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void Window::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::setVerticalSync(bool enabled) {
		(enabled) ? glfwSwapInterval(1) : glfwSwapInterval(0);
		m_Data.wd_VertSyncOn = enabled;
	}

	bool Window::isVerticalSyncOn() const {
		return m_Data.wd_VertSyncOn;
	}
}

#endif