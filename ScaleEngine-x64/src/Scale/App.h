#pragma once

#include "Core.h"
#include "../../src/Window.h"
#include "Events/AppEvent.h"

namespace Scale {

	//Главный класс движка
	class SCALE_API App {
	public:
		App();
		~App();

		void Run();

		void onEvent(Event& a);
	private:
		bool onWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	App* CreateApp();
}