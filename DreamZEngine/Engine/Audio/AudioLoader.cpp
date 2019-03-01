#include "AudioLoader.h"

std::unique_ptr<AudioLoader> AudioLoader::audioLoaderInstance = nullptr;
std::map<std::string, AudioLoader*> AudioLoader::audio = std::map<std::string, AudioLoader*>();



AudioLoader* AudioLoader::GetInstance()
{
	if (audioLoaderInstance.get() == nullptr) {
		audioLoaderInstance.reset(new AudioLoader);
	}

	return audioLoaderInstance.get();
}

AudioLoader::AudioLoader()
{
	
	
}
AudioLoader::~AudioLoader()
{
	for (auto ad : audio) {
		delete ad.second;
		ad.second = nullptr;
	}
	audio.clear();
	Mix_Quit();
}

void AudioLoader::PlayMusic(std::string fileName_, int loops)
{
	Mix_PlayMusic(AudioHandler::GetInstance()->GetMusic(fileName_), loops);
	
}
void AudioLoader::PauseMusic()
{
	if (Mix_PlayingMusic != 0)
	{
		Mix_PauseMusic();
	}
}
void AudioLoader::ResumeMusic()
{
	if (Mix_PausedMusic != 0)
	{
		Mix_ResumeMusic();
	}
}

void AudioLoader::PlaySFX(std::string fileName_, int loops, int channel)
{
	Mix_PlayChannel(channel, AudioHandler::GetInstance()->GetSFX(fileName_), loops);
}