#include "Application.h"

Woaf::Application* Woaf::Application::instance = nullptr;

Woaf::Application::Application() : active(true) {

}

Woaf::Application::~Application() {

}

Woaf::Application* Woaf::Application::GetInstance() {
	if (nullptr == instance) {
		instance = new Woaf::Application();
	}
	return instance;
}

bool Woaf::Application::Run() {
	return active;
}

void Woaf::Application::Stop() {
	active = false;
}
