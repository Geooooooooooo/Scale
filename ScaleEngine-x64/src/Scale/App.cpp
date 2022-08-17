#include "../sl_pch.h"

#include "App.h"
#include "Events/AppEvent.h"
#include "Log.h"

namespace Scale {
	App::App() : m_Window{ Window::create() } {
		SL_CORE_INFO("App::App()");
	}

	App::~App() {}

	void App::Run() {
		SL_CORE_INFO("Main loop start.");

		while (true) {
			m_Window->onUpdate();
		}

		SL_CORE_INFO("Main loop end.");
	}
}