#include "Core.h"
#include "Entity.h"
#include "iostream"

#include <GL/glew.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace myengine
{

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> setup = std::make_shared<Core>();
  setup->running = false;
  setup->self = setup;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
	  std::cout << "SDL Failed to Init" << std::endl;
  }

  setup->window = SDL_CreateWindow("My Engine",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH, WINDOW_HEIGHT,
    SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

  if (!SDL_GL_CreateContext(setup->window))
  {
	  std::cout << "Failed create a context with window" << std::endl;
  }

  if(glewInit() != GLEW_OK)
  {
	  std::cout << "GLEW Failed to Init" << std::endl;
  }

  setup->device = alcOpenDevice(NULL);

  if (!setup->device)
  {
	  throw std::exception();
  }

  setup->context = alcCreateContext(setup->device, NULL);

  if (!setup->context)
  {
	  alcCloseDevice(setup->device);
	  throw std::exception();
  }

  if (!alcMakeContextCurrent(setup->context))
  {
	  alcDestroyContext(setup->context);
	  alcCloseDevice(setup->device);
	  throw std::exception();
  }

  return setup;
}

void Core::start()
{
  running = true;

  while(running)
  {

	SDL_Event event = {0};

    while(SDL_PollEvent(&event))
    {
	  if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }

    for(std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->update();
    }

    glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	//Display Here


    SDL_GL_SwapWindow(window);
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
