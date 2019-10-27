#include <iostream>
#include <gl/glew.h>

#include "WFApplication.h"

#undef main // disabling SLD main function (included elsewhere)
int main()
{
	while (Woaf::WFApplication::GetInstance ()->Run ()) {
		
	}

	return 0;
}