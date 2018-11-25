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

  std::shared_ptr<myengine::Entity> Enemy = core->addEntity();
  glm::vec3 ePos = { -1.0f, -6.5f, -22.0f };
  Enemy->addComponent<myengine::MeshRenderer>("../resources/model/cat.obj", "../resources/model/cat_tex.png", ePos);

  std::shared_ptr<myengine::Entity> Object = core->addEntity();
  glm::vec3 oPos = { -1.0f, -6.5f, -22.0f };
  Enemy->addComponent<myengine::MeshRenderer>("../resources/model/hall.obj", "../resources/model/hall_tex.png", oPos);


  //THIS WORKS, WTF
  /*std::shared_ptr<myengine::Entity> p = p1->getEntity();
  std::shared_ptr<myengine::Sound> lol = p->getComponent<myengine::Sound>();
  lol->play();*/
  
  core->start();

  return 0;
}
