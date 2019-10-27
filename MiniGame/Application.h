#pragma once

#include <SDL.h>

#include <iostream>
#include <string>
#include <exception>

namespace Woaf
{

class Application
{
private:
	static Application* instance;
	bool active;

	explicit Application();
	~Application();

public:
	static Application* GetInstance();
	bool Run();
	void Stop();
};

}

