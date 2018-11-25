#ifndef INPUT_H
#define INPUT_H

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

		bool checkSpace() { return space; }
		void setSpace(bool x) { space = x; }

	private:
		bool space = false;
	};

}

#endif