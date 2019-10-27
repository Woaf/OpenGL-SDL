#pragma once

#include <memory>
#include <SDL.h>

#include "WFGeneralException.h"

namespace Woaf
{

#define WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL

class WFWindowException : public WFGeneralException
{
public: 
	WFWindowException (const std::string& error, size_t line, const char* file) : WFGeneralException (error, line, file) {}
};


class WFWindow
{
private: 
	SDL_Window* mainWindow;
public: 
	WFWindow (const std::string&, size_t, size_t);
	WFWindow (const std::string&, size_t, size_t, size_t, size_t);
	~WFWindow ();
};

}

