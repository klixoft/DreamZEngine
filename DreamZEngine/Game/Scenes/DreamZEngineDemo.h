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
#include "../../Engine/Rendering/2D/SliderUI.h"
#include "../Systems/ProjectileManager.h"
#include "../Units/Player.h"
#include "../Units/BaseUnit_0.h"
#include "../Objects/Map1.h"
#include "../Objects/Ball.h"
#include "../Objects/Goal.h"

enum DEMOREEL {
	DEMO1,
	DEMO2,
	DEMO3,
	DEMO4,
	DEMO5,
	DEFAULT
};

struct DemoText {
	std::string first;
	std::string second;
	std::string third;
	std::string fourth;
	std::string fifth;
	std::string sixth;
	std::string seventh;
};
	class DreamZEngineDemo : public Scene
	{
	public:
		DreamZEngineDemo();
		~DreamZEngineDemo();

		// Every scene requires these five methods to be implemented
		bool Initialize();
		void Update(const float deltaTime);
		void FixedUpdate(const float deltaTime);
		void HandleEvents(SDL_Event events);
		void HandleStates(const Uint8 *state);
		void CollsionCheck();
		void DemoState();
		void DemoKeyCheck(SDL_Event button);

		bool Demo1Checked = false;
	private:
		// Lights
		Light* pointLight;
		Light* dirLight;

		// Objects
		Player* player1;  //P1
		Player* player2;  //P2
		Player* player3;  //P3
		Player* player4;  //P4


		Map1* map;
		Ball* ball;
		Ball* ball2;
		Cube* floor;
		Cube* Demo1Cube;
		Cube* Demo2Cube;
		Cube* Demo3Cube;
		Cube* Demo4Cube;
		Cube* Demo5Cube;
		

		DEMOREEL demoEnum = DEFAULT;
		DemoText demoText;
		float demoImpulse = 180.0f;
		// UI
		TextUI* scoreBoard;
		int Team1Score;
		int Team2Score;

		SliderUI* sliderTEST;
		float chargeValue = 0.0f;
		bool chargeShot = false;


		float rotTest = 0.0f;
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
		vector<Cube*> collisionObjectList;

		// other variables
		float moveSpeed = 2;
		float deltaTime;
	};

#endif

