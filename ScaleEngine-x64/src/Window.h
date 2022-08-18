#pragma once

#include "sl_pch.h"

#include "Scale/Core.h"
#include "Scale/Events/Event.h"

#include "../../Libs/include/GLFW/glfw3.h"

namespace Scale {

	struct WindowProps {
		std::string Title;
		UINT Width;
		UINT Height;

		WindowProps(const std::string& title = "Scale Engine!", UINT width = 1200, UINT height = 700)
			: Title{ title }, Width{ width }, Height{ height } {}
	};

	class SCALE_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowProps&);
		virtual ~Window();
		void onUpdate();
		UINT getWidth() { return m_Data.wd_Widht; };
		UINT getHeight() {  return m_Data.wd_Height; };

		void setEventCallback(const EventCallbackFn& callback) { 
			m_Data.wd_EventCallback = callback; 
		};
		void setVerticalSync(bool);
		bool isVerticalSyncOn() const;

		void Init(const WindowProps&);
		void shutdown();

		static Window* create(const WindowProps& props = WindowProps());

	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string wd_Title = "";
			UINT wd_Widht = 0U, wd_Height = 0U;
			bool wd_VertSyncOn = false;

			EventCallbackFn wd_EventCallback = 0;
		};

		WindowData m_Data;
	};
}