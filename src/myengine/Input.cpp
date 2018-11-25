#include "Input.h"
#include <iostream>
#include <vector>


namespace myengine
{
	Input::Input() { }
	Input::Input(std::string Input)
	{

	}

	void Input::initialize()
	{
	}

	void Input::update()
	{
		const Uint8 *event = SDL_GetKeyboardState(NULL);
		if (event[SDL_SCANCODE_SPACE]) 
		{
			space = true;
			//std::cout << "<Space> is pressed.\n" << std::endl;
		}
		if (event[SDL_SCANCODE_RIGHT] && event[SDL_SCANCODE_UP]) 
		{
			std::cout << "Right and Up Keys Pressed.\n" << std::endl;
		}
	}

}