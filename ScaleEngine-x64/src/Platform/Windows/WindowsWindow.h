/*#pragma once

#include "../../Window.h"
#include "../../Libs/include/GLFW/glfw3.h"

namespace Scale {

	class WindowsWindow : public Window {
	public:
		friend class Window;

		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline UINT getWidth() override { return m_Data.wd_Widht; }
		inline UINT getHeight() override { return m_Data.wd_Height; }

		inline void setEventCallback(const EventCallbackFn& callback) override { m_Data.wd_EventCallback = callback; }
		void setVerticalSync(bool enabled) override;
		bool isVerticalSyncOn() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void shutdown();

		//WindowsWindow.h: main window
		GLFWwindow* m_Window;

		struct WindowData {
			std::string wd_Title;
			UINT wd_Widht, wd_Height;
			bool wd_VertSyncOn;

			EventCallbackFn wd_EventCallback;
		};

		WindowData m_Data;
	};
}*/