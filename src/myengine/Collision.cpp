#include "Collision.h"
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/ext.hpp>

namespace myengine
{
	Collision::Collision() { }
	Collision::Collision(std::string Collision)
	{

	}

	void Collision::initialize()
	{
		
	}

	void Collision::update()
	{

	}

	bool Collision::check(int aX, int aZ, int bX, int bZ)
	{
		glm::vec4 a = { (aX - 0.6), (aX + 0.6), (aZ - 0.4), (aZ + 0.4) };
		glm::vec4 b = { (bX - 0.4), (bX + 0.4), (bZ - 0.4), (bZ + 0.4) };

		return (a.x <= b.y && a.y >= b.x) &&
			   (a.z <= b.w && a.w >= b.z);
	}
}