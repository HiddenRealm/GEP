#ifndef MOVE_H
#define MOVE_H

#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include "Component.h"

namespace myengine
{

	class Move : public Component
	{

	public:
		Move();
		Move(std::string Move);

		void initialize();
		void update();

		int getPos() { return direction; }

	private:
		int direction;
		int flip;
		int oDir;

	};

}

#endif