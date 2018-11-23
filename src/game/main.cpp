#include <myengine/myengine.h>
#include <string>
#include <iostream>

class TestScreen : public myengine::Component
{
public:
  void initialize()
  {
	  std::cout << "Working" << std::endl;
  }

  void update()
  {
    //std::cout << "update" << std::endl;
  }
};

int main()
{
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();
  std::shared_ptr<myengine::Entity> entity = core->addEntity();
  std::shared_ptr<TestScreen> screen = entity->addComponent<TestScreen>();

  core->start();

  return 0;
}
