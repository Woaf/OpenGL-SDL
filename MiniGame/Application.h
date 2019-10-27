#pragma once

#include <SDL.h>

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

