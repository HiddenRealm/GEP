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
  void initialize(std::string shp, std::string tex, glm::vec3 pos);
  void update();
  void wrap();
  void setup(std::string shp, std::string tex);
  void setScale(glm::vec3 scl) { scale = scl; }
  void setPos(glm::vec3 nw) { pos += nw; }

  int getX() { return pos.x; }
  int getZ() { return pos.z; }
  int getY() { return pos.y; }
  void setY(int nPos) { pos.y = nPos; }

private:
  void display();

  VertexArray *shape;
  Texture *texture;
  ShaderProgram *shader;

  glm::vec3 camera;
  glm::vec3 scale;
  glm::vec3 pos;
  glm::mat4 model;
};

}

#endif
