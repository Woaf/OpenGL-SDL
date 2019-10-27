#include "Application.h"

Woaf::Application* Woaf::Application::instance = nullptr;

Woaf::Application::Application () : active(true) {
	try {
		if (0 != SDL_Init (SDL_INIT_EVERYTHING)) {
			throw ApplicationException ("SDL initialisation error occured.", __LINE__, __FILE__);
		}
		else {

		}
	}
	catch (ApplicationException& ex) {
		std::cerr << ex.what () << std::endl;
	}
}

Woaf::Application::~Application () {

}

Woaf::Application* Woaf::Application::GetInstance () {
	if (nullptr == instance) {
		instance = new Woaf::Application ();
	}
	return instance;
}

bool Woaf::Application::Run () {
	return active;
}

void Woaf::Application::Stop () {
	active = false;
}
