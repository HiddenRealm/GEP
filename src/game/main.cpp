#include <myengine/myengine.h>
#include <iostream>

int main()
{
	//Initialize the core of the engine
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();

  // Making all of my Entities
  std::shared_ptr<myengine::Entity> Player = core->addEntity();
  Player->addComponent<myengine::MeshRenderer>();
  Player->addComponent<myengine::Sound>("../resources/audio/Wilhelm.ogg");
  Player->addComponent<myengine::Input>();

  std::shared_ptr<myengine::Entity> Enemy = core->addEntity();
  Enemy->addComponent<myengine::MeshRenderer>();
  Enemy->addComponent<myengine::Input>();

  //THIS WORKS, WTF
  /*std::shared_ptr<myengine::Entity> p = p1->getEntity();
  std::shared_ptr<myengine::Sound> lol = p->getComponent<myengine::Sound>();
  lol->play();*/
  
  core->start();

  return 0;
}
