#include "Component.h"
#include "Entity.h"

namespace myengine
{
	//the component is a pretty hollow shell, it has the basic functions
	//that would need to be called on a decent amount of components
void Component::initialize() { }
void Component::update() { }
void Component::display() { }

	//it also holds these 2 functions that return the
	//Entity pointer & Core pointer respectfully
std::shared_ptr<Entity> Component::getEntity()
{
  return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
  return getEntity()->getCore();
}

}
