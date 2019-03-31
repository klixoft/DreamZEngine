#pragma once 
#ifndef DEMOUNIT_H
#define DEMOUNIT_H

#include "Player.h"


	class DemoUnit : public Player 
	{
	public:
		DemoUnit();
		~DemoUnit();

		// Attack Functions
		std::vector<Projectile*> LightAttack();
		std::vector<Projectile*> MediumAttack();
		std::vector<Projectile*> HeavyAttack();
		std::vector<Projectile*> SpecialAttack();

		void InheritedUpdate(const float deltaTime);
		void InheritedHandleEvents(SDL_Event events);
		void InheritedHandleStates(const Uint8 *state);

	public:
		bool airAttack = false;
	};



#endif
