#include <myengine/myengine.h>
#include <iostream>

int main()
{
	//Initialize the core of the engine
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();

  // Making all of my Entities
  std::shared_ptr<myengine::Entity> Player = core->addEntity();
  std::shared_ptr<myengine::Sound> p1 = Player->addComponent<myengine::Sound>("../audio/Wilhelm.ogg");
  Player->addComponent<myengine::Sound>("../audio/Joke.ogg");


  //THIS WORKS, WTF
  std::shared_ptr<myengine::Entity> p = p1->getEntity();
  std::shared_ptr<myengine::Sound> lol = p->getComponent<myengine::Sound>();
  lol->play();
  
  core->start();

  return 0;
}
