#include "Core.h"
#include "Entity.h"

#include <GL/glew.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace myengine
{

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> rtn = std::make_shared<Core>();
  rtn->running = false;
  rtn->self = rtn;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::exception();
  }

  rtn->window = SDL_CreateWindow("My Engine",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH, WINDOW_HEIGHT,
    SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

  if(!SDL_GL_CreateContext(rtn->window))
  {
    throw std::exception();
  }

  if(glewInit() != GLEW_OK)
  {
    throw std::exception();
  }

  rtn->device = alcOpenDevice(NULL);

  if(!rtn->device)
  {
    throw std::exception();
  }

  rtn->context = alcCreateContext(rtn->device, NULL);

  if(!rtn->context)
  {
    alcCloseDevice(rtn->device);
    throw std::exception();
  }

  if(!alcMakeContextCurrent(rtn->context))
  {
    alcDestroyContext(rtn->context);
    alcCloseDevice(rtn->device);
    throw std::exception();
  }
  return rtn;
}

void Core::start()
{
  running = true;
  float lastTime = SDL_GetTicks();
  float idealTime = 1.0f / 60.0f;


  while(running)
  {
	  if (idealTime > deltaTime)
	  {
		  SDL_Delay((idealTime - deltaTime) * 1000.0f);
	  }

	SDL_Event event = {0};

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }


    for(std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->tick();
    }

    glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->display();
    }

    SDL_GL_SwapWindow(window);

	float time = SDL_GetTicks();
	float diff = time - lastTime;
	float deltaTime = diff / 1000.0f;
	lastTime = time;
  }
}

void Core::stop()
{
  running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
  std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
  entities.push_back(rtn);
  rtn->self = rtn;
  rtn->core = self;

  return rtn;
}

}
