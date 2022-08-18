#include "../sl_pch.h"

#include "App.h"
//nclude "Events/AppEvent.h"
#include "Log.h"

#include "../../Libs/include/GLFW/glfw3.h"

namespace Scale {

//Макрос связывающий функцию и аргумент
#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)

	App::App() : m_Window{ (std::unique_ptr<Window>)Window::create() } {

		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	App::~App() {}

	void App::onEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		SL_CORE_TRACE("{0}", event.toString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->onEvent(event);
			if (event.m_Handled) break;
		}
	}

	bool App::onWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}

	void App::pushLayer(Layer_ptr layer) {
		m_LayerStack.pushLayer(layer);
	}

	void App::pushOverlay(Layer_ptr layer) {
		m_LayerStack.popOverlay(layer);
	}

	void App::Run() {
		SL_CORE_INFO("Main loop start.");

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer_ptr l : m_LayerStack) {
				l->onUpdate();
			}

			m_Window->onUpdate();
		}

		SL_CORE_INFO("Main loop end.");
	}
}