#ifndef KEYBOARDEVENTLISTENER_H
#define KEYBOARDEVENTLISTENER_H

#include <SDL.h>
#include <glm/glm.hpp>

class EngineClass;

class KeyboardEventListener
{
public:
	KeyboardEventListener(const KeyboardEventListener&) = delete;
	KeyboardEventListener(KeyboardEventListener&&) = delete;
	KeyboardEventListener& operator=(const KeyboardEventListener&) = delete;
	KeyboardEventListener& operator=(KeyboardEventListener&&) = delete;

	static void RegisterEngineObject(EngineClass* engine_);
	static void Update(SDL_Event e, const float deltaTime);
	static void NotifyOfMousePressed(int buttonType);
	static void NotifyOfMouseReleased(int buttonType);
	static void NotifyOfMouseMoved();
	static void NotifyOfMouseScroll(int y_);
	static glm::vec2 GetPreviousMousePosition();
	static glm::vec2 GetMousePosition();
	static glm::vec2 GetMouseOffset();
	~KeyboardEventListener();

private:
	static EngineClass* engineInstance;
	static int mouseX, mouseY, prevMouseX, prevMouseY;
	static bool firstUpdate;
	static void UpdateMousePosition();

};



#endif