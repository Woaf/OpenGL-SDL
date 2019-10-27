#pragma once

#include <SDL.h>

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

namespace Woaf
{

class GeneralException : public std::runtime_error
{
protected:
public: 
	explicit GeneralException (const std::string& error, size_t line = __LINE__, const char* file = __FILE__) 
		: std::runtime_error (error + "\n\tat line: " + std::to_string(line) + "\n\tin file: " + file) {}
};

class ApplicationException : public Woaf::GeneralException
{	
public:
	explicit ApplicationException (const std::string& error, size_t line = __LINE__, const char* file = __FILE__) 
		: GeneralException (error, line, file) {}
};

class Application
{
private:
	static Application* instance;
	bool active;

	explicit Application ();
	~Application ();

public:
	static Application* GetInstance ();
	bool Run ();
	void Stop ();
};

}

