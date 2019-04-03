#ifndef Goal_H
#define Goal_H

#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Core/RenderComponent.h"
#include "../../Engine/Math/CollisionComponent.h"
#include "../../Engine/Math/PhysicsComponent.h"
#include "../../Engine/Math/PhysicsEngine.h"
#include "../../Engine/Graphics/Shader.h"
#include "../../Engine/Timers/Cooldown.h"
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/compatibility.hpp>
#include "ObjectBase.h"

// Properties of the Goal that is saved and used during gameplay by the Goal manager




class Goal : public GameObject
{
public:
	// Constructors
	Goal();
	virtual ~Goal();


	// Loop functions
	// DO NOT OVERRIDE THIS FUNCTION
	void Update(const float deltaTime);
	void FixedUpdate(const float deltaTime);
	//
	// Children use this method
	virtual void InheritedUpdate(const float deltaTime) {};
	// DO NOT OVERRIDE THIS FUNCTION
	void HandleEvents(SDL_Event events);
	//
	// Children use this method
	virtual void InheritedHandleEvents(SDL_Event events) {};
	// DO NOT OVERRIDE THIS FUNCTION
	void HandleStates(const Uint8 *state);
	//
	// Children use this method
	virtual void InheritedHandleStates(const Uint8 *state) {};
	// Render
	void Render(Shader* shader, const double _interpolation);

	void Bounce();
protected:
	// Player model parts
	ObjectBase* base;


	// Player Stats



};



#endif
