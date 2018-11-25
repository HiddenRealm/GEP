#include "Move.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <GL/glew.h>
#include <glm/ext.hpp>

namespace myengine
{
	Move::Move() { }
	Move::Move(std::string Move)
	{

	}

	void Move::initialize()
	{
		srand(time(NULL));

		direction = rand() % 4 + 1;
		oDir = 0;
	}

	void Move::update()
	{
		if (oDir == 0)
		{
			direction = rand() % 4 + 1;
			oDir = 10;
		}

		oDir--;

	}
}