#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include "Component.h"

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "Texture.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/ext.hpp>
#include <iostream>
#include <string>
#include <memory>

namespace myengine
{

class MeshRenderer : public Component
{
public:
  MeshRenderer();
  void initialize(std::string shp, std::string tex);
  void update();
  void setup(std::string shp, std::string tex);

private:
  void display();

  VertexArray *shape;
  Texture *texture;
  ShaderProgram *shader;

  glm::mat4 model;
};

}

#endif
