#include <Scale.h>
#include "../../ScaleEngine-x64/src/Scale/EnteryPoint.h"

class ExampleLayer : public Scale::Layer {
public:
	ExampleLayer(std::string layerName = "Example") : Layer(layerName) {}

	void onUpdate() override {
		SL_INFO("ExampleLayer::onUpdate");
	}

	void onEvent(Scale::Event& event) override {
		SL_TRACE(event.toString());
	}
};

class Sandbox : public Scale::App {
public:
	Sandbox() {
		pushLayer(new ExampleLayer());
	}

	~Sandbox() {}
};

Scale::App* Scale::CreateApp() {
	return new Sandbox();
}