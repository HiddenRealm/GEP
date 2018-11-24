#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include "Component.h"

namespace myengine
{

	struct SoundImpl;

	class Sound : public Component
	{
		std::shared_ptr<SoundImpl> impl;

	public:
		Sound();
		Sound(std::string path);
		void initialize(std::string path);
		void load(std::string path);
		void play();
		void update();

		bool isBigE();
		int convert(char* buffer, int len);
	};

}