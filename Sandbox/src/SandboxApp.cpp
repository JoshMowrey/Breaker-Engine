#include <Breaker.h>
class Sandbox : public Breaker::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};


Breaker::Application* Breaker::CreateApplication() {
	return new Sandbox();
}
