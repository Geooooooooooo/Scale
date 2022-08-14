#pragma once

#include "Core.h"

namespace Scale {

	//Главный класс движка
	class SCALE_API App {
	public:
		App();

		virtual ~App();

		void Run();
	};

	App* CreateApp();
}