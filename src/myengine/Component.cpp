#include "Component.h"
#include "Entity.h"

namespace myengine
{
void Component::initialize() { }
void Component::update() { }

std::shared_ptr<Entity> Component::getEntity()
{
  return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
  return getEntity()->getCore();
}

}
