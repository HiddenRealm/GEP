#include "Entity.h"

namespace myengine
{

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}

void Entity::tick()
{
  for(std::vector<std::shared_ptr<Component>>::iterator it = components.begin();
    it != components.end(); it++)
  {
    if(!(*it)->began)
    {
      (*it)->began = true;
    }

    (*it)->update();
  }
}
}
