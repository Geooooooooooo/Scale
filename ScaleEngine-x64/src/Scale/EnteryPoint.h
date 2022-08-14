#pragma once

#ifdef SL_WINDOWS_PLATFORM

extern Scale::App* Scale::CreateApp();

//������� ����� � ���������
int main(int argc, char** argv) {
	//������������ �������
	Scale::Log::Init();
	SL_CORE_WARN("Initialized Log!");

	//�������� ����������
	auto app = Scale::CreateApp();
	app->Run();
	delete app;
}

#endif // SL_WINDOWS_PLATFORM
