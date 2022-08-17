#pragma once

#include "App.h"

#ifdef SL_WINDOWS_PLATFORM

extern Scale::App* Scale::CreateApp();

int main(int argc, char** argv) {
	Scale::Log::Init();

	auto app = Scale::CreateApp();
	if(app == nullptr) { SL_CORE_INFO("App was not created!"); exit(-2); }

	app->Run();
	delete app;
}

#endif // SL_WINDOWS_PLATFORM
