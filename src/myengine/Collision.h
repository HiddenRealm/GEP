#ifndef COLLISION_H
#define COLLISION_H

#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include "Component.h"

namespace myengine
{

	class Collision : public Component
	{

	public:
		Collision();
		Collision(std::string Collision);

		void initialize();
		void update();
		//returns if the entities have collided
		bool check(int aX, int aZ, int bX, int bZ);

	private:

	};

}

#endif