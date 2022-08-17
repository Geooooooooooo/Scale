#pragma once

#include "Core.h"
#include "../../src/Window.h"

namespace Scale {

	//Главный класс движка
	class SCALE_API App {
	public:
		App();
		~App();

		void Run();
	private:
		Window* m_Window;
		bool m_Runung = true;
	};

	App* CreateApp();
}