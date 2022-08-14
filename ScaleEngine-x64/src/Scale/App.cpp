#include "App.h"
#include "Events/AppEvent.h"
#include "Log.h"

namespace Scale {
	App::App() {

	}

	App::~App() {

	}

	void App::Run() {
		WindowResizeEvent e(1000, 800);
		SL_INFO(e.toString());
		SL_CORE_CRITICAL("Critical Message");

		while (true);
	}
}