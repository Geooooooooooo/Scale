#include "../sl_pch.h"

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
		if (e.isInCategory(EC_Application)) {
			SL_TRACE(e.toString());
		}
		if (e.isInCategory(EC_Input)) {
			SL_TRACE(e.toString());
		}

		while (true);
	}
}