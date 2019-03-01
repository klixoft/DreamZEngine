#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H
#include "MouseEventListener.h"
#include "KeyboardEventListener.h"
class EventListener
{
public:
	EventListener(const EventListener&) = delete;
	EventListener(EventListener&&) = delete;
	EventListener& operator=(const EventListener&) = delete;
	EventListener& operator=(EventListener&&) = delete;
	static void Update(const float deltaTime);

	
};

#endif EVENTLISTENER_H