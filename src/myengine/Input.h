#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include "Component.h"

namespace myengine
{

	class Input : public Component
	{

	public:
		Input();
		Input(std::string Input);

		void initialize();
		void update();
	};

}