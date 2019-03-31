#pragma once
#ifndef MAP1_H
#define MAP1_H

#include <SDL.h>
#include "../../Engine/Core/EngineClass.h"
//#include "../../Engine/Audio\Map1Dialogue.h"
#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Core/RenderComponent.h"

#include "Arena.h"



	// Forward declare Projectile Manager to avoid circular dependency 

// Base Map1 Class
class Map1 : public GameObject
{
public:
	// Constructors
	Map1();
	virtual ~Map1();


	// Loop functions
	// DO NOT OVERRIDE THIS FUNCTION
	void Update(const float deltaTime);
	void FixedUpdate(const float deltaTime);

	// Render
	void Render(Shader* shader, const double _interpolation);

	


protected:
	// Map1 model parts
	Arena* base;
	
};



#endif
