#pragma once 
#ifndef WINDPLAYER_H
#define WINDPLAYER_H

#include "Player.h"


	class BaseUnit_0 : public Player 
	{
	public:
		BaseUnit_0();
		~BaseUnit_0();

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
