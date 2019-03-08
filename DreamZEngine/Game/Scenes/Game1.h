#pragma once
#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "../../Engine/Core/EngineClass.h"
#include "../../Engine/Core/Scene.h"
#include "../../Engine/Core/Light.h"

#include "../../Engine/Rendering\3D\Cube.h"
#include "../../Engine/Rendering\3D\Projectile.h"
#include "../../Engine/Rendering\3D\Skybox.h"
#include "../../Engine/Graphics\Shader.h"
#include "../../Engine/Math\PhysicsEngine.h"
//#include "../Engine/Rendering\2D\TextUI.h>
#include "../Systems/ProjectileManager.h"
#include "../Units/Player.h"
#include "../Units/BaseUnit_0.h"



	class Game1 : public Scene
	{
	public:
		Game1();
		~Game1();

		// Every scene requires these five methods to be implemented
		bool Initialize();
		void Update(const float deltaTime);
		void FixedUpdate(const float deltaTime);
		void HandleEvents(SDL_Event events);
		void HandleStates(const Uint8 *state);

	private:
		// Lights
		Light* pointLight;
		Light* dirLight;

		// Objects
		Player* player1;  //P1
		Player* player2;  //P2
		Player* player3;  //P3
		Player* player4;  //P4

		Cube* floor;
		Cube* wall;
		Cube* wall1;
		Cube* middleWall;

		// shaders
		Shader* defaultShader;
		Shader* skyboxShader;

		// shader handles / reference to shader in the renderers shader manager
		Shader defaultShaderHandle;
		Shader skyboxShaderHandle;

		// scene manager
		SceneManager* sceneManager;

		// Projectile Manager
		ProjectileManager* projectileManager;

		// Player list
		vector<Player*> playerList;

		// other variables
		float moveSpeed = 2;
		float deltaTime;
	};

#endif

