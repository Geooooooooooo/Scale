#include <Scale.h>
#include "../../ScaleEngine-x64/src/Scale/EnteryPoint.h"

extern Scale::App* Scale::CreateApp();

class Sandbox : public Scale::App {
public:
	Sandbox() {}

	~Sandbox() {}
};

Scale::App* Scale::CreateApp() {
	return new Sandbox();
}