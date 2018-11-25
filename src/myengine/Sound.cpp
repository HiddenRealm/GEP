#include "Sound.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>
#include <iostream>
#include <vector>

namespace myengine
{

	struct SoundImpl : public Sound
	{
		ALuint id;

		~SoundImpl()
		{
			alDeleteBuffers(1, &id);
		}

		void load_ogg(std::string fileName, std::vector<char> &buffer,
			ALenum &format, ALsizei &freq)
		{
			int endian = isBigE();
			int bitStream = 0;
			long bytes = 0;
			char array[2048] = { 0 };
			vorbis_info *pInfo = NULL;
			OggVorbis_File oggFile = { 0 };

			// Use the inbuilt fopen to create a file descriptor
			if (ov_fopen(fileName.c_str(), &oggFile) != 0)
			{
				std::cout << "Failed to open file '" << fileName << "' for decoding" << std::endl;
				throw std::exception();
			}

			// Extract information from the file header
			pInfo = ov_info(&oggFile, -1);

			// Record the format required by OpenAL
			if (pInfo->channels == 1)
			{
				format = AL_FORMAT_MONO16;
			}
			else
			{
				format = AL_FORMAT_STEREO16;
			}

			// Record the sample rate required by OpenAL
			freq = pInfo->rate;

			// Keep reading bytes from the file to populate the output buffer
			while (true)
			{
				// Read bytes into temporary array
				bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

				if (bytes < 0)
				{
					ov_clear(&oggFile);
					std::cout << "Failed to decode file '" << fileName << "'." << std::endl;
					throw std::exception();
				}
				else if (bytes == 0)
				{
					break;
				}

				// Copy from temporary array into output buffer
				buffer.insert(buffer.end(), array, array + bytes);
			}

			// Clean up and close the file
			ov_clear(&oggFile);
		}
	};

	Sound::Sound() { }

	Sound::Sound(std::string path)
	{
		load(path);
	}

	void Sound::initialize(std::string path)
	{
		load(path);
	}

	void Sound::update()
	{

	}

	void Sound::load(std::string path)
	{
		impl = std::make_shared<SoundImpl>();

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		alGenBuffers(1, &impl->id);

		impl->load_ogg(path.c_str(), bufferData, format, freq);

		alBufferData(impl->id, format, &bufferData[0],
			static_cast<ALsizei>(bufferData.size()), freq);
	}

	void Sound::play()
	{
		ALuint sid = 0;
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, impl->id);
		alSourcePlay(sid);

		//audioSources.push_back(sid);
	}

	bool Sound::isPlaying()
	{
		ALenum state;
		ALuint sid = 0;
		alGenSources(1, &sid);
		alGetSourcei(sid, AL_SOURCE_STATE, &state);

		return (state == AL_PLAYING);
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
}