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
		bool checkW() { return w; }
		bool checkA() { return a; }
		bool checkS() { return s; }
		bool checkD() { return d; }

	private:
		bool space = false;
		bool w = false;
		bool a = false;
		bool s = false;
		bool d = false;
	};

}

#endif