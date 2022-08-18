#include "sl_pch.h"
#include "../../ScaleEngine-x64/src/Scale/Log.h"
#include "../../Libs/include/GLFW/glfw3.h"

#include "../../ScaleEngine-x64/src/Scale/Events/AppEvent.h"
#include "../../ScaleEngine-x64/src/Scale/Events/KeyEvent.h"
#include "../../ScaleEngine-x64/src/Scale/Events/MouseEvent.h"

#ifdef SL_WINDOWS_PLATFORM
#include "Window.h"

namespace Scale {
	static bool s_GLFWinited = false;

	static void GLFWErrorCallback(int errCode, const char* errorText) {
		SL_CORE_ERROR("GLFW Error '{0}': {1}", errCode, errorText);
	}

	Window::Window(const WindowProps& props = WindowProps()) {
		Init(props);
	}

	Window::~Window() {
		shutdown();
	}

	Window* Window::create(const WindowProps& props) {
		return new Window(props);
	}

	void Window::Init(const WindowProps& props) {
		m_Data.wd_Title = props.Title;
		m_Data.wd_Height = props.Height;
		m_Data.wd_Widht = props.Width;

		if (!s_GLFWinited) {
			int success = glfwInit();
			
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWinited = true;
		}

		SL_CORE_INFO("Creating a window '{0}' ({1}, {2})", props.Title, props.Width, props.Height);
		
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.wd_Title.c_str(), 0, 0);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVerticalSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int w, int h) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.wd_Widht = w;
			data.wd_Height = h;

			WindowResizeEvent event(w, h);
			data.wd_EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.wd_EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scanCode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					data.wd_EventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					data.wd_EventCallback(event);
						break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					data.wd_EventCallback(event);
					break; 
				}
			}

		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mode) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					data.wd_EventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					data.wd_EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offset_x, double offset_y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseScrolledEvent event(offset_x, offset_y);
			data.wd_EventCallback(event);

		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event(x, y);
			data.wd_EventCallback(event);
		});

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