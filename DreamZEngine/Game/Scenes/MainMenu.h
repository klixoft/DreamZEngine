#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "../../Engine/Core/EngineClass.h"
#include "../../Engine/Core/Scene.h"
#include "../../Engine/Core/Light.h"
//#include <BlueFlameEngine\Engine\Core\ResourceManager.h>
#include "../../Engine/Rendering\3D\Skybox.h"
#include "../../Engine/Graphics\Shader.h"
#include "../../Engine/Rendering\2D\TextUI.h"
#include "../../Engine/Rendering\2D\ImageUI.h"
#include "../../Engine/Rendering\2D\ButtonUI.h"
//#include "DemoScene.h"
#include "DreamZEngineDemo.h"
//#include "MenuSelectScene.h"



	class MainMenu : public Scene
	{
	public:
		MainMenu();
		~MainMenu();

		// Every scene requires these three methods to be implemented
		bool Initialize();
		void Update(const float deltaTime);
		void FixedUpdate(const float deltaTime);
		void HandleEvents(SDL_Event events);
		void HandleStates(const Uint8 *state);

		SceneManager* sceneManager;
	private:
		// shaders
		Shader* skyboxShader;

		// shader handles / reference to shader in the renderers shader manager
		Shader skyboxShaderHandle;

		// UI
		TextUI* titleText;
		TextUI* startText;
		TextUI* creditText;

		float z = 0;
	};

#endif

