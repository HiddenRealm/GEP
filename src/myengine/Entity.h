#include "Component.h"

#include <memory>
#include <vector>

namespace myengine
{

class Core;

class Entity
{
  friend class Core;

public:

  template <typename T>
  std::shared_ptr<T> addComponent()
  {
	std::shared_ptr<T> rtn = std::make_shared<T>();
	rtn->entity = self;
	rtn->began = false;
	components.push_back(rtn);
    rtn->initialize();

    return rtn;
  }

  template <typename T>
  std::shared_ptr<T> getComponent()
  {
	  for (size_t i = 0; i < components.size(); i++)
	  {
		  std::shared_ptr<T> list = std::dynamic_pointer_cast<T>(components.at(i));

		  if (list)
		  {
			  return list;
		  }
	  }

	  std::cout << "Failed to load Components" << std::endl;
  }

  std::shared_ptr<Core> getCore();

private:
  std::weak_ptr<Entity> self;
  std::weak_ptr<Core> core;
  std::vector<std::shared_ptr<Component> > components;

  void tick();

};

}
