#pragma once
#include "Window.h"
#include "GameState.h"

class ApplicationException : public std::runtime_error
{
public: 
	ApplicationException (const std::string& error) : std::runtime_error (error) {}
};

class Application {
private: 
	Application ();
	~Application ();
	static Application* applicationInstance;
	bool active = true;
	Window* window;
	GameState* state;

public: 
	static Application* GetInstance ();

	bool Run ();
	void Stop ();

	template <class T>
	void SetState();
};