#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#include <memory>
#include <map>
#include <SDL_mixer.h>
#include"../Core/Debug.h"

enum AudioEnum
{
	MUSIC,
	SFX
};
struct AudioType {



};
class AudioHandler
{
public:

	AudioHandler(const AudioHandler&) = delete;
	AudioHandler(AudioHandler&&) = delete;
	AudioHandler& operator=(const AudioHandler&) = delete;
	AudioHandler& operator=(AudioHandler&&) = delete;


	static AudioHandler* GetInstance();

	void AddAudio(const std::string& name_, const std::string& filePath_, AudioEnum audioType_);
	Mix_Music* GetMusic(const std::string& fileName_);
	Mix_Chunk* GetSFX(const std::string& fileName_);
	void init();

private:

	static std::unique_ptr<AudioHandler> audioHandlerInstance;
	friend std::default_delete<AudioHandler>;

	static std::map<std::string, AudioEnum> audio;
	static std::map<std::string, Mix_Music*> music;
	static std::map<std::string, Mix_Chunk*> sfx;
	
	AudioHandler();
	
	~AudioHandler();
};



#endif // !AUDIOHANDLER_H

