#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include "EngineClass.h"

using namespace std;

//Initialize static variables
std::unique_ptr<EngineClass> EngineClass::EngineClassInstance(nullptr);
Window* EngineClass::window(nullptr);

//Initialize member variables
EngineClass::EngineClass() : isRunning(false), firstLoad(true), sceneManager(nullptr), windowName("Blue Flame Engine"), width(1280), height(720)
{

}

EngineClass::~EngineClass()
{
	cout << "Shutting down..." << endl;

	

	delete sceneManager;
	sceneManager = nullptr;

	TerminateGame();
}

void EngineClass::TerminateGame()
{
	exit(0);

	window->Shutdown();
	window = nullptr;

	SDL_Quit();
}

EngineClass* EngineClass::GetInstance()
{
	if (EngineClassInstance.get() == nullptr) {
		EngineClassInstance.reset(new EngineClass);
	}
	return EngineClassInstance.get();
}

bool EngineClass::Initialize()
{
	// Create a new window
	window = new Window();
	// Iniitalize the window with the window name and size
	window->Initialize(windowName, width, height);
	cout << "Window initialized to " << window->GetWidth() << " by " << window->GetHeight() << endl;

	// Initialize Scene Manager
	sceneManager = new SceneManager();
	sceneManager->Initialize(window);
	cout << "Scene Manager Initialized" << endl;

	// Initialize clock
	Clock::GetInstance()->init();
	cout << "Clock Initialized" << endl;

	// Set up controllers
//	InputManager::GetInstance()->initalizeControllers();

	cout << "EngineClass Initialized" << endl;

	Settings::getInstance()->loadSettings("settings.txt");

	//if (Settings::getInstance()->networkedGame) {
	//	if (Settings::getInstance()->isServer) {
	//		return setUpNetworkAsServer();
	//	}
	//	else {
	//		return setUpNetworkAsClient();
	//	}
	//}

	return true;
}

void EngineClass::Run()
{
	// Set the engine to running
	isRunning = true;

	// Set up timer
	Timer::GetInstance().Start();

	// Number of fixed ticks per second
	const int ticksPerSecond = 100;

	// The amount of ticks to skip per frame
	const int skipTicks = 1000 / ticksPerSecond;

	// The amount of frames the physics step can skip before slowing down
	const int maxFrameSkip = 5;

	// The next game tick the fixed loop will take place at
	DWORD nextGameTick = GetTickCount();

	// Number of loops the fixed update has between the rendered frames
	int loops;

	// Set the fixed update to run 120 times per second
	// This keeps it in the multiples of common refresh rates
	double fixedDeltaTime = 8.3333333333333333;

	// Current time since the system has started
	double currentTime = GetTickCount();

	// Accumulator that keeps track of the time between fixed updates and rendered frames 
	double accumulator = 0.0;

	while (isRunning)
	{
		// Check if the scene manager has quit
		if (sceneManager->IsQuit()) {
			isRunning = false;
		}

		// Calculate frame time between rendering
		double newTime = GetTickCount();
		double frameTime = newTime - currentTime;

		// Clamp the frame time so in cases where the rendered frames suffer,
		// slowing down the fixed update to help adjust
		if (frameTime > 250.0)
			frameTime = 250.0;

		currentTime = newTime;

		accumulator += frameTime;

		// This loop is called dependent on the fixedDeltaTime
		while (accumulator >= fixedDeltaTime) {

			// Game and physics logic that rely on a constant behaviour 
			// between systems should be done in this update
			UpdateState();
			FixedUpdate(fixedDeltaTime * 0.001);
			accumulator -= fixedDeltaTime;
		}

		// Update timer
		Timer::GetInstance().Update();

		// Because a rendering frame can occur between two fixed updates, the renderer
		// can assume based on input and velocity from the previous frame
		// where the objects in a scene will be in the next rendering frame
		// This interpolation represents that inbetween render state of the objects
		// and is passed to the renderer
		interpolation = accumulator / fixedDeltaTime;

		// Other graphic logic that is not physics and game dependent should
		// be done as desired in this update

		Update(Timer::GetInstance().GetDeltaTime());
		PreRender();
		Render();
		PostRender();

		// Only display window after the first render has been called
		if (firstLoad) {
			cout << "Displaying window..." << endl;
			SDL_ShowWindow(window->GetWindow());
			firstLoad = false;
		}
	}
}

void EngineClass::UpdateState() {
	sceneManager->UpdateState();
}

void EngineClass::FixedUpdate(const float deltaTime)
{
	sceneManager->FixedUpdate(deltaTime);
	sceneManager->HandleEvents();
}

void EngineClass::Update(const float deltaTime)
{
	sceneManager->Update(deltaTime);
}

void EngineClass::PreRender()
{
	sceneManager->PreRender();
}

void EngineClass::Render()
{
	sceneManager->Render(interpolation);
}

void EngineClass::PostRender()
{
	sceneManager->PostRender();
}

SceneManager* EngineClass::GetSceneManager()
{
	return sceneManager;
}

void EngineClass::SetWindowName(std::string name)
{
	windowName = name;
}

void EngineClass::SetWindowDimensions(int width, int height)
{
	this->width = width;
	this->height = height;
}

// Networking
