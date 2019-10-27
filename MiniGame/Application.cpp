#include "Application.h"

Application* Application::instance = nullptr;

Application::Application() : active(true) {

}

Application::~Application() {

}

Application* Application::GetInstance() {
	if (nullptr == instance) {
		instance = new Application();
	}
	return instance;
}

bool Application::Run() {
	return active;
}

void Application::Stop() {
	active = false;
}
