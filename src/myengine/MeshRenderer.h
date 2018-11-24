#include "Component.h"

#include <memory>

namespace myengine
{

class VertexArray;
class ShaderProgram;

class MeshRenderer : public Component
{
public:
  void initialize();

private:
  void display();

  std::shared_ptr<VertexArray> shape;
  std::shared_ptr<ShaderProgram> shader;

};

}
