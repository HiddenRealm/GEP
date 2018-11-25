#include "MeshRenderer.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <iostream>

namespace myengine
{

MeshRenderer::MeshRenderer() { }

void MeshRenderer::initialize(std::string shp, std::string tex, glm::vec3 _pos)
{
	camera = { 0, 13.0f, -17.0f };
	pos = _pos;
	scale = { 1,1,1 };
	glm::mat4 _model(1.0f);
	model = _model;
	setup(shp, tex);
}

void MeshRenderer::setup(std::string shp, std::string tex)
{
	update();
	shape = new VertexArray(shp);
	texture = new Texture(tex);
}

void MeshRenderer::update()
{
	shader = new ShaderProgram("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	shader->setUniform("in_Projection", glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.f));

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(camera.x, camera.y, camera.z));
	model = glm::rotate(model, glm::radians(270.0f), glm::vec3(1, 0, 0));
	shader->setUniform("in_View", glm::inverse(model));

	model = glm::mat4(1.0f);
	wrap();
	model = glm::translate(model, glm::vec3(pos.x , pos.y, pos.z));
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));
}

void MeshRenderer::wrap()
{
	if (pos.x < -10)
	{
		pos.x = 10;
	}
	if (pos.x > 10)
	{
		pos.x = -10;
	}
	if (pos.z < -25)
	{
		pos.z = -9;
	}
	if (pos.z > -9)
	{
		pos.z = -25;
	}
}

void MeshRenderer::display()
{
  shader->setUniform("in_Model", model);
  shader->setUniform("in_Texture", texture);
  shader->draw(shape);
}

}
