#include "Core/EngineClass.h"
#include "../Game/Scenes/Game1.h"
#include "../Game/Scenes/MainMenu.h"
#include "../Game/Scenes/UnitSelection.h"


int main(int argc, char* args[])
{
	
	//Version 1
	/*if (!EngineClass::GetInstance()->Initialize("FartBox", 800, 600))
	{
		
		return 0;
	}*/

	//VERSION 2
	EngineClass::GetInstance()->SetWindowName("DreamZ Engine");
	EngineClass::GetInstance()->SetWindowDimensions(1280, 720);

	//Start Engine
	if (EngineClass::GetInstance()->Initialize()) {
		// Add scenes
		EngineClass::GetInstance()->GetSceneManager()->AddScene(new MainMenu);
		EngineClass::GetInstance()->GetSceneManager()->AddScene(new UnitSelection);
		EngineClass::GetInstance()->GetSceneManager()->AddScene(new Game1);
		EngineClass::GetInstance()->GetSceneManager()->StartScene();
		//Game Loop
		EngineClass::GetInstance()->Run();
	}

	return 0;
}