#ifndef AUDIOLOADER_H
#define AUDIOLOADER_H

#include "AudioHandler.h"


class AudioLoader
{
public:



	static AudioLoader* GetInstance();

	AudioLoader(const AudioLoader&) = delete;
	AudioLoader(AudioLoader&&) = delete;
	AudioLoader& operator=(const AudioLoader&) = delete;
	AudioLoader& operator=(AudioLoader&&) = delete;

	static void PlayMusic(std::string fileName_, int loops = -1);
	void PauseMusic();
	void ResumeMusic();


	static void PlaySFX(std::string fileName_, int loops = 0, int channel = 0);


private:
	AudioLoader();
	~AudioLoader();
	
	static std::unique_ptr<AudioLoader> audioLoaderInstance;
	friend std::default_delete<AudioLoader>;

	static std::map<std::string, AudioLoader*> audio;

};



#endif // !AUDIOLOADER_H


