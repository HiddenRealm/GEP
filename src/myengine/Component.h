#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{

class Entity;
class Core;

class Component
{
  friend class Entity;

public:
  std::shared_ptr<Core> getCore();
  std::shared_ptr<Entity> getEntity();

private:
	//holds its pointer to the entity its attached to.
  std::weak_ptr<Entity> entity;
  bool began;

  //Importantly sets these functions to virtual voids
  virtual void initialize();
  virtual void update();
  virtual void display();
};

}

#endif
