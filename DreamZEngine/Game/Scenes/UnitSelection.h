#pragma once
#ifndef UNITSELECTION_H
#define UNITSELECTION_H


#include "../../Engine/Rendering\2D\SliderUI.h"
#include "../../Engine/Core/EngineClass.h"
#include "../../Engine/Core/Scene.h"
#include "../../Engine/Core/Light.h"
//#include <BlueFlameEngine\Engine\Core\ResourceManager.h>
#include "../../Engine/Rendering\3D\Skybox.h"
#include "../../Engine/Graphics\Shader.h"
#include "../../Engine/Rendering\2D\TextUI.h"
#include "../../Engine/Rendering\2D\ImageUI.h"
#include "../../Engine/Rendering\2D\ButtonUI.h"
#include "DreamZEngineDemo.h"



class UnitSelection : public Scene
{
public:
	UnitSelection();
	~UnitSelection();

	// Every scene requires these three methods to be implemented
	bool Initialize();
	void Update(const float deltaTime);
	void FixedUpdate(const float deltaTime);
	void HandleEvents(SDL_Event events);
	void HandleStates(const Uint8 *state);

	SceneManager* sceneManager;
private:
	// shaders
	Shader* defaultShader;
	Shader* skyboxShader;

	// shader handles / reference to shader in the renderers shader manager


	// UI
	TextUI* titleText;

	ButtonUI* Unit1Button;
	ButtonUI* Unit2Button;
	ButtonUI* Unit3Button;
	ButtonUI* buttonExit;

	SliderUI* sliderTEST;

	Model* Unit1;
	Model* Unit2;
	Model* Unit3;

	Player* player1;  //P1
	Player* player2;  //P2
	Player* player3;  //P3
	Player* player4;  //P4

	BaseUnit_0* base;
	// Lights
	Light* pointLight;
	Light* dirLight;
};

#endif

