#include "AudioHandler.h"

std::unique_ptr<AudioHandler> AudioHandler::audioHandlerInstance = nullptr;
std::map<std::string, AudioEnum> AudioHandler::audio = std::map<std::string, AudioEnum>();

std::map<std::string, Mix_Music*> AudioHandler::music = std::map<std::string, Mix_Music*>();
std::map<std::string, Mix_Chunk*> AudioHandler::sfx = std::map<std::string, Mix_Chunk*>();

AudioHandler::AudioHandler()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	{
		Debug::Error("Mixer Initialization Error: pop ", __FILE__, __LINE__);
	}
}

void AudioHandler::init()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	{
		Debug::Error("Mixer Initialization Error: pop ", __FILE__, __LINE__);
	}
}

AudioHandler::~AudioHandler()
{
	if (audio.size() > 0)
	{
		audio.clear();
	}
}

AudioHandler*  AudioHandler::GetInstance()
{
	if (audioHandlerInstance.get() == nullptr)
	{
		audioHandlerInstance.reset(new AudioHandler);
	}
	return audioHandlerInstance.get();
}



Mix_Music* AudioHandler::GetMusic(const std::string& name_)
{
	std::string fullPath = "Resources/Audio/";
	fullPath.append(name_);
	std::cout <<  name_;
	if (music[fullPath] == nullptr)
	{
		music[fullPath] = Mix_LoadMUS(fullPath.c_str());
		if (music[fullPath] == NULL)
		{
			Debug::Error("Couldnt Load Music File: " + fullPath,__FILE__,__LINE__);
			printf(Mix_GetError());
		}
	}
	
	return music[fullPath];


}

Mix_Chunk* AudioHandler::GetSFX(const std::string& name_)
{
	std::string fullPath = "Resources/Audio/";
	fullPath.append(name_);
	//	std::cout << name_;
	if (sfx[fullPath] == nullptr)
	{
		sfx[fullPath] = Mix_LoadWAV(fullPath.c_str());
		if (sfx[fullPath] == NULL)
		{
			Debug::Error("Couldnt Load SFX File: " + name_, __FILE__, __LINE__);
			printf(Mix_GetError());
		}
	}

	return sfx[fullPath];
}




