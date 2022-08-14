#pragma once

#ifdef SL_WINDOWS_PLATFORM

extern Scale::App* Scale::CreateApp();

//Входная точка в программу
int main(int argc, char** argv) {
	//Инициализаия логгера
	Scale::Log::Init();
	SL_CORE_WARN("Initialized Log!");

	//Создание приложения
	auto app = Scale::CreateApp();
	app->Run();
	delete app;
}

#endif // SL_WINDOWS_PLATFORM
