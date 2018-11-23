#include "Sound.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>
#include <fstream>

namespace myengine
{
	Sound::Sound() { }
	Sound::Sound(std::string path)
	{
		read(path.c_str());
	}

	void Sound::play()
	{
		ALCdevice* device = alcOpenDevice(NULL);
		if (device == NULL)
		{
			throw std::exception();
		}

		ALCcontext* context = alcCreateContext(device, NULL);
		if (context == NULL)
		{
			throw std::exception();
		}

		alcMakeContextCurrent(context);

		unsigned int bufferid, format;
		alGenBuffers(1, &bufferid);
		if (channel == 1)
		{
			if (beats == 8)
			{
				format = AL_FORMAT_MONO8;
			}
			else {
				format = AL_FORMAT_MONO16;
			}
		}
		else {
			if (beats == 8)
			{
				format = AL_FORMAT_STEREO8;
			}
			else {
				format = AL_FORMAT_STEREO16;
			}
		}
		alBufferData(bufferid, format, data, size, sample);
		unsigned int sourceid;
		alGenSources(1, &sourceid);
		alSourcei(sourceid, AL_BUFFER, bufferid);
		alSourcePlay(sourceid);
	}

	bool Sound::isBigE()
	{
		int x = 1;
		return !((char*)&x)[0];
	}

	int Sound::convert(char* buffer, int len)
	{
		int x = 0;

		if (isBigE())
		{
			for (int i = 0; i < len; i++)
			{
				((char*)&x)[i] = buffer[i];
			}
		}
		else 
		{
			for (int i = 0; i < len; i++)
			{
				((char*)&x)[3-i] = buffer[i];
			}
		}
		return x;
	}

	void Sound::read(const char* name)
	{
		char buffer[4];
		std::ifstream in(name, std::ios::binary);
		in.read(buffer, 4);
		if (strncmp(buffer, "RIFF", 4) != 0)
		{
			throw std::exception();
			std::cout << "Not a WAV" << std::endl;
		}
		in.read(buffer, 4);
		in.read(buffer, 4);
		in.read(buffer, 4);
		in.read(buffer, 4);
		in.read(buffer, 2);
		in.read(buffer, 2);
		channel = convert(buffer, 2);
		in.read(buffer, 4);
		sample = convert(buffer, 4);
		in.read(buffer, 4);
		in.read(buffer, 2);
		in.read(buffer, 2);
		beats = convert(buffer, 2);
		in.read(buffer, 4);
		in.read(buffer, 4);
		size = convert(buffer, 4);
		data = new char[size];
		in.read(data, size);
		data = data;
	}
}