#include "MeshRenderer.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <iostream>

namespace myengine
{

MeshRenderer::MeshRenderer() { }

void MeshRenderer::initialize(std::string shp, std::string tex)
{
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
	shader->setUniform("in_View", glm::inverse(model));
	

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0, -2.1f, -20.0f));
	model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0, 1, 0));
}


void MeshRenderer::display()
{
  shader->setUniform("in_Model", model);
  shader->setUniform("in_Texture", texture);
  shader->draw(shape);
}

}
