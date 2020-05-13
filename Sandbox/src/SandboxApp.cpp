#include <York.h>

class Sandbox : public York::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

York::Application* York::CreateApplication() {
	return new Sandbox();
}
