#include "KeyboardEventListener.h"
#include"../Core/EngineClass.h"

//EngineClass* KeyboardEventListener::engineInstance = nullptr;

EngineClass* KeyboardEventListener::engineInstance = nullptr;
int KeyboardEventListener::mouseX = 0;
int KeyboardEventListener::mouseY = 0;
int KeyboardEventListener::prevMouseX = 0;
int KeyboardEventListener::prevMouseY = 0;
bool KeyboardEventListener::firstUpdate = true;


KeyboardEventListener::~KeyboardEventListener() {
	engineInstance = nullptr;
}

void KeyboardEventListener::RegisterEngineObject(EngineClass * engine_) {
	engineInstance = engine_;
}

void KeyboardEventListener::Update(SDL_Event e, const float deltaTime) {
	/*if (e.key.keysym.sym == SDLK_UP) {
		Camera::GetInstance()->ProcessKeyboard(FORWARD, deltaTime);
	}
	else if (e.key.keysym.sym == SDLK_DOWN) {
		Camera::GetInstance()->ProcessKeyboard(BACKWARD, deltaTime);
	}
	else if (e.key.keysym.sym == SDLK_LEFT) {
		Camera::GetInstance()->ProcessKeyboard(LEFT, deltaTime);
	}
	else if (e.key.keysym.sym == SDLK_RIGHT) {
		Camera::GetInstance()->ProcessKeyboard(RIGHT, deltaTime);
	}*/
	
		
}