#include <Scale.h>

class Sandbox : public Scale::App {
public:
	Sandbox() {}

	~Sandbox() {}
};

Scale::App* Scale::CreateApp() {
	return new Sandbox();
}