#pragma once

#include "Core.h"

namespace Scale {
	class SCALE_API App {
	public:
		App();

		virtual ~App();

		void Run();
	};

	App* CreateApp();
}