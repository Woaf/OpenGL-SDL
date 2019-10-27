#pragma once

#include "WFWindow.h"

namespace Woaf
{

class WFApplicationException : public Woaf::WFGeneralException
{	
public:
	explicit WFApplicationException (const std::string& error, size_t line = __LINE__, const char* file = __FILE__) 
		: WFGeneralException (error, line, file) {}
};


class WFApplication
{
private:
	static WFApplication* instance;
	bool active;
	WFWindow* window;

	explicit WFApplication ();
	~WFApplication ();

public:
	static WFApplication* GetInstance ();
	bool Run ();
	void Stop ();
};

}

