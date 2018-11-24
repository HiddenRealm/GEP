#include "Entity.h"

namespace myengine
{

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}

void Entity::update()
{
  for(std::vector<std::shared_ptr<Component>>::iterator count = components.begin();
	  count != components.end(); count++)
  {
    if(!(*count)->began)
    {
      (*count)->began = true;
    }

    (*count)->update();
  }
}

void Entity::display()
{
	for (std::vector<std::shared_ptr<Component> >::iterator count = components.begin();
		count != components.end(); count++)
	{
		(*count)->display();
	}
}
}
