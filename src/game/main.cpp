#include <myengine/myengine.h>
#include <string>
#include <iostream>

class TestScreen : public myengine::Component
{
public:
  void onInit(std::string color)
  {
	std::cout << "Working" << std::endl;
	std::cout << color << std::endl;
  }

  void onBegin()
  {
    //std::cout << "onBegin" << std::endl;
  }

  void onTick()
  {
    //std::cout << "onTick" << std::endl;
  }

  void onDisplay()
  {
    //std::cout << "onTick" << std::endl;
  }
};

int main()
{
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();

  std::shared_ptr<myengine::Entity> entity = core->addEntity();

  //std::shared_ptr<myengine::Sound> sound = std::make_shared<myengine::Sound>("dixie_horn.ogg");
  //sound->play();

  std::shared_ptr<TestScreen> screen = entity->addComponent<TestScreen>("Green");
  //std::shared_ptr<myengine::MeshRenderer> meshrender = entity->addComponent<myengine::MeshRenderer>();
  //std::shared_ptr<myengine::MeshRenderer> meshrender2 = entity->getComponent<myengine::MeshRenderer>();

  core->start();

  return 0;
}
