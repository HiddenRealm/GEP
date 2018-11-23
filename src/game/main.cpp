#include <myengine/myengine.h>
#include <string>
#include <iostream>

class TestScreen : public myengine::Component
{
public:
  void initialize()
  {
	  std::cout << "Working" << std::endl;
	  /*for (int i = 0; i > ; i++)
	  {

	  }*/
  }

  void update()
  {
    std::cout << "update" << std::endl;
	/*for (int i = 0; i > ; i++)
	{

	}*/
  }
};

int main()
{
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();
  std::shared_ptr<myengine::Entity> entity = core->addEntity();

  std::shared_ptr<myengine::Object> o1 = std::make_shared<myengine::Object>("This is text from Object 1");
  std::shared_ptr<myengine::Sound> a1 = std::make_shared<myengine::Sound>("audio\Correct.wav");
  a1->play();

  std::shared_ptr<TestScreen> screen = entity->addComponent<TestScreen>();

  core->start();

  return 0;
}
