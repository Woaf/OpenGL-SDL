#pragma once

#include <memory>
#include <SDL.h>

#include "WFGeneralException.h"

namespace Woaf
{

#define WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
#define RENDER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

class WFWindowException : public WFGeneralException
{
public: 
	WFWindowException (const std::string& error, size_t line, const char* file) : WFGeneralException (error, line, file) {}
};


class WFRendererException : public WFGeneralException
{
public: 
	WFRendererException (const std::string& error, size_t line, const char* file) : Woaf::WFGeneralException (error, line, file) {}
};

class WFWindow
{
private: 
	SDL_Window* mainWindow;
	SDL_Renderer* renderer;

public: 
	WFWindow (const std::string&, size_t, size_t);
	WFWindow (const std::string&, size_t, size_t, size_t, size_t);
	void InitRenderer ();
	~WFWindow ();
};

}

