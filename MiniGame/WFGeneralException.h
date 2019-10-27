#pragma once

#include <iostream>
#include <string>
#include <exception> // not necessary for MSVC17

namespace Woaf 
{

class WFGeneralException : public std::runtime_error
{
protected:
public:
	explicit WFGeneralException(const std::string& error, size_t line = __LINE__, const char* file = __FILE__)
		: std::runtime_error(error + "\n\tat line: " + std::to_string(line) + "\n\tin file: " + file) {}
};

}