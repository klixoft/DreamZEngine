#pragma once

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

#ifndef ENGINECLASS_H
#define ENGINECLASS_H

#include <memory>
#include "Window.h"
#include "SceneManager.h"
#include "Timer.h"
#include "../Timers/MasterClock.h"
//#include "InputHandling/InputManager.h"
#include "../Debuging/Settings.h"
#include "../Debuging/Replay.h"



	// SINGLETON CLASS
	class EngineClass
	{
	public:
		// Delete default constructors
		EngineClass(const EngineClass&) = delete;
		EngineClass(EngineClass&&) = delete;
		EngineClass& operator=(const EngineClass&) = delete;
		EngineClass& operator=(EngineClass&&) = delete;

		bool Initialize();
		void Run();
		void UpdateState();
		void FixedUpdate(const float deltaTime);
		void Update(const float deltaTime);
		void PreRender();
		void Render();
		void PostRender();

		// Get the current version of this class
		static EngineClass* GetInstance();

		// Get the scene manager
		SceneManager* GetSceneManager();

		// Window option setters
		void SetWindowName(std::string name);
		void SetWindowDimensions(int width, int height);

		// Clean up
		static void TerminateGame();

		// Networking
		std::string receiveData();
		void sendData(std::string data);


	private:
		// Private Constructor and Destructor so no other class can create it
		EngineClass();
		~EngineClass();

		static std::unique_ptr<EngineClass> EngineClassInstance;
		friend std::default_delete<EngineClass>;

		// Running check
		bool isRunning;
		bool firstLoad;

		// Window
		static Window* window;

		// Scene Manager
		SceneManager* sceneManager;

		// Window options
		std::string windowName;
		int width;
		int height;

		// Interpolation between fixed game loop and rendering loop
		double interpolation;

		

		//struct pollfd ufds[1];
	};


#endif
