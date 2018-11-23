#include <memory>
#include <string>

namespace myengine
{

	class Sound
	{

	public:
		Sound();
		Sound(std::string path);
		void play();

		bool isBigE();
		int convert(char* buffer, int len);
		void read(const char* name);

		int channel, sample, beats, size;
		char* data;
	};

}