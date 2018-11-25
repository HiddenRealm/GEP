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
		}
		else
		{
		space = false;
		}

		if (event[SDL_SCANCODE_W]) 
		{
			w = true;
		}
		else
		{
			w = false;
		}

		if (event[SDL_SCANCODE_A])
		{
			a = true;
		}
		else
		{
			a = false;
		}

		if (event[SDL_SCANCODE_S])
		{
			s = true;
		}
		else
		{
			s = false;
		}

		if (event[SDL_SCANCODE_D])
		{
			d = true;
		}
		else
		{
			d = false;
		}
	}

}