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
	
	//Not much to be said in this 'Component'
	//this function simply inputs the a(x & Z) & b(x & z)
	//takes them and adds them to 2 vec4 for simplicity
	//if this engine was more fleshed out i wouldnt hard code these values
	//i would have either different collision checks for each entity type
	//or more likely send in the maxX & minX for each value
	bool Collision::check(int aX, int aZ, int bX, int bZ)
	{
		glm::vec4 a = { (aX - 0.6), (aX + 0.6), (aZ - 0.4), (aZ + 0.4) };
		glm::vec4 b = { (bX - 0.4), (bX + 0.4), (bZ - 0.4), (bZ + 0.4) };

		return (a.x <= b.y && a.y >= b.x) &&
			   (a.z <= b.w && a.w >= b.z);
	}
}