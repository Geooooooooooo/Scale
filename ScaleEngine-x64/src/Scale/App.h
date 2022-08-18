#pragma once

#include "Core.h"
#include "../../src/Window.h"
#include "Events/AppEvent.h"
#include "LayerStack.h"
#include "Layer.h"

namespace Scale {

	//Главный класс движка
	class SCALE_API App {
	public:
		App();
		~App();

		void Run();

		void onEvent(Event&);

		void pushLayer(Layer_ptr);
		void pushOverlay(Layer_ptr);
	private:
		bool onWindowClose(WindowCloseEvent&);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	App* CreateApp();
}