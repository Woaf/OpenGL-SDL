#include "WFApplication.h"

Woaf::WFApplication* Woaf::WFApplication::instance = nullptr;

Woaf::WFApplication::WFApplication () : active (true), window (nullptr) {
	try {
		if (0 != SDL_Init (SDL_INIT_EVERYTHING)) {
			throw WFApplicationException ("SDL initialisation error occured.", __LINE__, __FILE__);
		}
		else {
			window = new WFWindow ("My first SDL window", 720, 480);
		}
	}
	catch (WFApplicationException& ex) {
		std::cerr << ex.what () << std::endl;
	} 
	catch (WFWindowException& ex) {
		std::cerr << ex.what () << std::endl;
	}
}

Woaf::WFApplication::~WFApplication () {
	SDL_Quit ();
}

Woaf::WFApplication* Woaf::WFApplication::GetInstance () {
	if (nullptr == instance) {
		instance = new Woaf::WFApplication ();
	}
	return instance;
}

bool Woaf::WFApplication::Run () {
	if (active) {
		SDL_Event event;
		while (SDL_PollEvent (&event)) {
			switch (event.key.keysym.sym) {
				case (SDLK_ESCAPE):  
				Stop ();
				break;
			}
		}
	}
	return active;
}

void Woaf::WFApplication::Stop () {
	active = false;
}
