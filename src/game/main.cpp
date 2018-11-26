#include <myengine/myengine.h>
#include <iostream>

int main()
{
  //Initialize the core of the engine
  std::shared_ptr<myengine::Core> core = myengine::Core::initialize();

  // Making all of my Entities
  //Start with the Player
  std::shared_ptr<myengine::Entity> Player = core->addEntity();
  //Set a starting position
  glm::vec3 pPos = { -1.0f, -6.5f, -12.0f };
  //Add the 3D meshRenderer Component, Send in the Object.file, Texture,file & the set Position
  Player->addComponent<myengine::MeshRenderer>("resources/model/play.obj", "resources/model/play_tex.png", pPos);
  //Get a link to that Component
  std::shared_ptr<myengine::MeshRenderer> p = Player->getComponent<myengine::MeshRenderer>();
  //Use it to set & update the scale of the Object
  glm::vec3 pScl = { 1, 1, 1 };
  p->setScale(pScl);
  //Add the Sound Component, linking the audio file
  Player->addComponent<myengine::Sound>("resources/audio/Bike.ogg");
  //Stick on Collision & Input, not only do these class have small amounts of code, 
  //but they also allow me to refine my search in my systems
  Player->addComponent<myengine::Collision>();
  Player->addComponent<myengine::Input>();

  //Add 10 Enemy Entities
  for (int i = 0; i < 10; i++)
  {
	  std::shared_ptr<myengine::Entity> Enemy = core->addEntity();
	  //Varying Positions
	  glm::vec3 ePos = { i, -6.5f, -i };
	  //Same as before with the player
	  Enemy->addComponent<myengine::MeshRenderer>("resources/model/cat.obj", "resources/model/cat_tex.png", ePos);
	  std::shared_ptr<myengine::MeshRenderer> e = Enemy->getComponent<myengine::MeshRenderer>();
	  glm::vec3 eScl = { 0.3f, 0.3f, 0.3f };
	  e->setScale(eScl);
	  Enemy->addComponent<myengine::Sound>("resources/audio/Wilhelm.ogg");
	  Enemy->addComponent<myengine::Move>();
	  Enemy->addComponent<myengine::Collision>();
  }

  //Add the Background Entity
  //way less components, as the background isnt expected to do anything.
  std::shared_ptr<myengine::Entity> Hall = core->addEntity();
  glm::vec3 hPos = { -1.0f, -6.5f, -22.0f };
  Hall->addComponent<myengine::MeshRenderer>("resources/model/hall.obj", "resources/model/hall_tex.png", hPos);
  Hall->addComponent<myengine::Sound>("resources/audio/Win.ogg");

  //Run The main loop
  core->start();

  return 0;
}
