/*#include "../../sl_pch.h"

#include "WindowsWindow.h"
#include "../../Scale/Log.h"
#include "../../Scale/Core.h"

namespace Scale {
	static bool s_GLFWinited = false;

	Window* Window::create(const WindowProps& props) {
		return (Window*)new WindowProps(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		SL_CORE_INFO("[WindowsWindow.cpp]$ Init in WIndowsWindow construction!");
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.wd_Title = props.Title;
		m_Data.wd_Height = props.Height;
		m_Data.wd_Widht = props.Width;

		SL_CORE_INFO("Creating a window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWinited) {
			int success = glfwInit();
			SL_CORE_ERROR(success);

			s_GLFWinited = true;
		}

		SL_CORE_INFO("[WindowsWindow.cpp:36]$ glfwCreateWindow");
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.wd_Title.c_str(), 0, 0);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVerticalSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
		SL_CORE_INFO("App updated!");
	}

	void WindowsWindow::setVerticalSync(bool enabled) {
		(enabled) ? glfwSwapInterval(1) : glfwSwapInterval(0);
		m_Data.wd_VertSyncOn = enabled;
	}

	bool WindowsWindow::isVerticalSyncOn() const {
		return m_Data.wd_VertSyncOn;
	}
	
}*/