#include <York.h>

class ExampleLayer : public York::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		YK_INFO("Example Layer On Update");
	}

	void OnEvent(York::Event& event) {
		YK_TRACE("Example Layer On Event | Event {0}", event);
	}
};

class Sandbox : public York::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new York::ImGuiLayer());
	}

	~Sandbox() {

	}
};

York::Application* York::CreateApplication() {
	return new Sandbox();
}
