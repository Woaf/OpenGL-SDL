#include "Window.h"

void Window::InitRenderer ()
{
	this->context = SDL_GL_CreateContext (this->mainWindow);
	if (nullptr == this->context) {
		throw GlContextException (SDL_GetError ());
	} else {
		if (SDL_GL_SetSwapInterval (1) < 0) {
			throw GlContextException (SDL_GetError ());
		}
	}
}

Window::Window (const std::string & title, int width, int height)
{
	this->mainWindow = SDL_CreateWindow (title.c_str (),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_FLAGS);
	if (nullptr == this->mainWindow) {
		throw WindowException(SDL_GetError ());
	} else {
		this->InitRenderer ();
	}
}

Window::Window (const std::string& title, int startPosX, int startPosY, int width, int height)
{
	this->mainWindow = SDL_CreateWindow (title.c_str(), 
		startPosX, startPosY, width, height, 
		SDL_WINDOW_FLAGS);
}

void Window::Update ()
{
	SDL_GL_SwapWindow(this->mainWindow);
}

Window::~Window ()
{
	SDL_GL_DeleteContext (this->context);
	SDL_DestroyWindow (this->mainWindow);
}
