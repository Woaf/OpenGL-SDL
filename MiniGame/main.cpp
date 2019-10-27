#include <iostream>
#include <gl/glew.h>
#include <SDL.h>
#undef main // disabling SLD main function

#include "Application.h"

int main()
{
	while (Woaf::Application::GetInstance ()->Run ()) {
		
	}

	return 0;
}