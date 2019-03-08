#include "MainMenu.h"


MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
	sceneManager = nullptr;
}

bool MainMenu::Initialize()
{
	// Make reference to the scene manager
	sceneManager = EngineClass::GetInstance()->GetSceneManager();

	// Set camera options
	cameraList[0]->Yaw = 0.0f;
	cameraList[0]->Zoom = 105.0f;

	// Set screen options
	sceneManager->EnableFullscreen(false);
	//sceneManager->ShowFPS(true);
	//sceneManager->GetRenderer()->EnableBloom(true);

	// Load shaders
	skyboxShader = new Shader("Engine/Shaders/skybox.vs", "Engine/Shaders/skybox.fs");

	// Put shaders into shader manager
	//skyboxShaderHandle = sceneManager->GetRenderer()->GetShaderManager()->put(std::string("skybox"), skyboxShader);

	// Make skybox, load its textures, set properties, and give to the renderer
	skybox = new Skybox();
	std::vector<std::string> faces;
	faces.push_back("Resources/Skybox/Skyboxes/image.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/image.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/image.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/image.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/image.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/image.jpg");
	skybox->LoadTextures(faces);
	skybox->SetShader(skyboxShader);

	// UI
	titleText = new TextUI();
	titleText->SetFont("Resources/Fonts/arial.ttf");
	titleText->SetText("UBERBALL");
	titleText->SetColour(0.0, 0.0f, 0.0f);
	titleText->SetSize(1.3f);
	titleText->SetSpacing(9.0f);
	titleText->SetPosition(sceneManager->GetScreenWidth() / 2 - titleText->GetLength() / 2, sceneManager->GetScreenHeight() / 2);

	startText = new TextUI();
	startText->SetText("Press Start/Space to play");
	startText->SetColour(0.6f, 0.6f, 0.6f);
	startText->SetSize(0.30f);
	startText->SetSpacing(50.0f);
	startText->SetPosition(sceneManager->GetScreenWidth() / 2 - startText->GetLength() / 2, titleText->GetPosition().y + 300.0f);

	creditText = new TextUI();
	creditText->SetText("(C) 2019 DREAMZ");
	creditText->SetColour(0.0f, 0.0f, 0.0f);
	creditText->SetSize(0.30f);
	creditText->SetPosition(sceneManager->GetScreenWidth() - creditText->GetLength() - 15.0f, sceneManager->GetScreenHeight() - 15.0f);

	AddUIObject(titleText);
	AddUIObject(startText);
	AddUIObject(creditText);

	return true;
}

void MainMenu::Update(const float deltaTime)
{
	float fade = (sin(z += deltaTime) / 2.0f) + 0.5f;
	startText->SetAlpha(fade);
	//cameraList[0]->SetRotationY(cameraList[0]->Yaw += deltaTime * 5);

	

}

void MainMenu::FixedUpdate(const float deltaTime)
{

}

void MainMenu::HandleEvents(SDL_Event events)
{
	
}

void MainMenu::HandleStates(const Uint8 *state)
{
	if (state[SDL_SCANCODE_SPACE]) {
		sceneManager->NextScene();
	}
}