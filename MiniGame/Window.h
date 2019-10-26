#pragma once
#include <iostream>
#include <exception>

#include <GL/glew.h>
#include <SDL.h>

#define SDL_WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE

class WindowException : public std::runtime_error
{
public:
	WindowException (const std::string& error) : std::runtime_error (error) {}
};

class GlContextException : public std::runtime_error
{
public:
	GlContextException (const std::string& error) : std::runtime_error (error) {}
};

class Window
{
private: 
	void InitRenderer ();
	SDL_Window* mainWindow;
	SDL_GLContext context;
public: 
	Window (const std::string& title, int, int);
	Window (const std::string&, int, int, int, int);
	void Update ();
	~Window ();
};

