#include "EventListener.h"
#include "../Core/EngineClass.h"





void EventListener::Update(const float deltaTime)
{
	SDL_Event SDLEvent;
	/*while (SDL_PollEvent(&SDLEvent))
	{
		switch (SDLEvent.type)
		{
		case SDL_QUIT:
			EngineClass::GetInstance()->ExitGame();
			break;
		case SDL_MOUSEBUTTONDOWN:
			
		case SDL_MOUSEBUTTONUP:
		
		case SDL_KEYDOWN:
			KeyboardEventListener::Update(SDLEvent,deltaTime);
		case SDL_MOUSEMOTION:
		
		case SDL_MOUSEWHEEL:
			MouseEventListener::Update(SDLEvent);
			break;
		default:
			break;
		}
	}*/
}
