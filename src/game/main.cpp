#include <myengine/myengine.h>
#include <iostream>

int main()
{
  //Initialize the core of the engine
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();

  // Making all of my Entities
  std::shared_ptr<myengine::Entity> Player = core->addEntity();
  glm::vec3 pPos = { -1.0f, -6.5f, -12.0f };
  Player->addComponent<myengine::MeshRenderer>("../resources/model/play.obj", "../resources/model/play_tex.png", pPos);
  std::shared_ptr<myengine::MeshRenderer> p = Player->getComponent<myengine::MeshRenderer>();
  glm::vec3 pScl = { 1, 1, 1 };
  p->setScale(pScl);
  Player->addComponent<myengine::Sound>("../resources/audio/Wilhelm.ogg");
  Player->addComponent<myengine::Input>();

  for (int i = 0; i < 10; i++)
  {
	  std::shared_ptr<myengine::Entity> Enemy = core->addEntity();
	  glm::vec3 ePos = { i, -6.5f, -i };
	  Enemy->addComponent<myengine::MeshRenderer>("../resources/model/cat.obj", "../resources/model/cat_tex.png", ePos);
	  std::shared_ptr<myengine::MeshRenderer> e = Enemy->getComponent<myengine::MeshRenderer>();
	  glm::vec3 eScl = { 0.3f, 0.3f, 0.3f };
	  e->setScale(eScl);
	  Enemy->addComponent<myengine::Move>();
  }

  std::shared_ptr<myengine::Entity> Hall = core->addEntity();
  glm::vec3 hPos = { -1.0f, -6.5f, -22.0f };
  Hall->addComponent<myengine::MeshRenderer>("../resources/model/hall.obj", "../resources/model/hall_tex.png", hPos);


  //THIS WORKS, WTF
  /*std::shared_ptr<myengine::Entity> p = p1->getEntity();
  std::shared_ptr<myengine::Sound> lol = p->getComponent<myengine::Sound>();
  lol->play();*/
  
  core->start();

  return 0;
}
