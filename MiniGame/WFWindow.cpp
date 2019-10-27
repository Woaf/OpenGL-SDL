#include "WFWindow.h"

Woaf::WFWindow::WFWindow (const std::string& title, size_t width, size_t height) {
	mainWindow = SDL_CreateWindow (title.c_str (), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, WINDOW_FLAGS);
	renderer = nullptr;

	if (nullptr == mainWindow) {
		throw WFWindowException (SDL_GetError (), __LINE__, __FILE__);
	} 
	else {
		InitRenderer ();
	}
}

Woaf::WFWindow::WFWindow (const std::string& title, size_t x, size_t y, size_t width, size_t height) {
	mainWindow = SDL_CreateWindow (title.c_str (), x, y, width, height, WINDOW_FLAGS);
	renderer = nullptr;

	if (nullptr == mainWindow) {
		throw WFWindowException (SDL_GetError (), __LINE__, __FILE__);
	}
	else {
		InitRenderer ();
	}
}

void Woaf::WFWindow::InitRenderer () {
	renderer = SDL_CreateRenderer (mainWindow, -1, RENDER_FLAGS);
	if (nullptr == renderer) {
		throw WFRendererException (SDL_GetError(), __LINE__, __FILE__);
	}
}

Woaf::WFWindow::~WFWindow () {
	SDL_DestroyWindow (mainWindow);
}
