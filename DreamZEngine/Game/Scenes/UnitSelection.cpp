#include "UnitSelection.h"



UnitSelection::UnitSelection()
{
}

UnitSelection::~UnitSelection()
{
	sceneManager = nullptr;
}

bool UnitSelection::Initialize()
{
	// Make reference to the scene manager
	sceneManager = EngineClass::GetInstance()->GetSceneManager();

	// If you plan to use the scenemanagers scene vector you dont need to set these values all the time
	// Set camera options
	cameraList[0]->Yaw = 0.0f;
	cameraList[0]->Zoom = 45.0f;

	// Set screen options
	sceneManager->EnableSplitscreen(false);
	sceneManager->EnableFullscreen(false);
	sceneManager->ShowFPS(true);
	sceneManager->GetRenderer()->EnableBloom(true);
	sceneManager->CaptureMouse(false);
	// Load shaders
	defaultShader = new Shader("Engine/Shaders/model.vs", "Engine/Shaders/model.fs");
	skyboxShader = new Shader("Engine/Shaders/skybox.vs", "Engine/Shaders/skybox.fs");

	// Put shaders into shader manager
	player1 = new BaseUnit_0();
	player1->SetWorldScale(0.5f);
	player1->SetShader(defaultShader);
	player1->SetWorldPosition(glm::vec3(-2.0f, 0.0f, 3.0f));
	player1->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER1);
	player1->SetPlayerTeam(Player::PLAYERTEAM::TEAM1);

	//	player1->GetPlayerInput()->AddAnyController();


	// Player 2
	player2 = new BaseUnit_0();
	//player2->dialogue.channel = 2;
	player2->SetShader(defaultShader);
	player2->SetWorldPosition(glm::vec3(2.0f, 0.0f, 3.0f));
	player2->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER2);
	player2->SetPlayerTeam(Player::PLAYERTEAM::TEAM1);
	player2->SetWorldScale(0.5f);
	//player2->GetPlayerInput()->AddAnyController();
	//player2->AddProjecitleManager(projectileManager);

	// Player 3
	player3 = new BaseUnit_0();
	//player3->dialogue.channel = 3;
	player3->SetShader(defaultShader);
	player3->SetWorldPosition(glm::vec3(2.0f, 0.0f, -3.0f));
	player3->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER3);
	player3->SetPlayerTeam(Player::PLAYERTEAM::TEAM2);
	player3->SetWorldScale(0.05f);
	//player3->GetPlayerInput()->AddAnyController();
	//player3->AddProjecitleManager(projectileManager);

	// Player 4
	player4 = new BaseUnit_0();
	//player4->dialogue.channel = 4;
	player4->SetShader(defaultShader);
	player4->SetWorldPosition(glm::vec3(-2.0f, 0.0f, -3.0f));
	player4->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER4);
	player4->SetPlayerTeam(Player::PLAYERTEAM::TEAM2);
	player4->SetWorldScale(0.05f);
	//player4->GetPlayerInput()->AddAnyController();
	//player4->AddProjecitleManager(projectileManager);
	// Make skybox, load its textures, set properties, and give to the renderer
	skybox = new Skybox();
	std::vector<std::string> faces;
	faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/right.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/left.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/top.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/bottom.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/back.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/ame_nebula/front.jpg");
	skybox->LoadTextures(faces);
	skybox->SetShader(skyboxShader);

	// UI
	titleText = new TextUI();
	//titleText->SetFont("Resources/Fonts/ka1.ttf");
	titleText->SetText("PICK YOUR UNIT");
	titleText->SetColour(1.0, 1.0f, 1.0f);
	titleText->SetSize(0.8f);
	titleText->SetSpacing(9.0f);
	titleText->SetPosition(50, -100);

	Unit1Button = new ButtonUI("Resources/Textures/DefaultButton.png");
	Unit1Button->SetPosition(-(Unit1Button->GetWidth() / 2) - 150, (Unit1Button->GetHeight() / 2) + 300);
	Unit1Button->SetHeight(500);
	Unit1Button->SetPadding(-10, 0);
	Unit1Button->GetText()->SetText("UNIT 1");
	Unit1Button->SetTextPadding(75, 35);
	Unit1Button->GetImage()->SetAlpha(0.5f);

	Unit2Button = new ButtonUI("Resources/Textures/DefaultButton.png");
	Unit2Button->SetPosition(800, Unit1Button->GetPosition().y);
	Unit2Button->SetHeight(500);
	Unit2Button->SetPadding(-10, 0);
	Unit2Button->GetText()->SetText("UNIT 2");
	//Unit2Button->GetText()->SetSize(0.8f);
	Unit2Button->SetTextPadding(75, 35);
	Unit2Button->GetImage()->SetAlpha(0.5f);

	Unit3Button = new ButtonUI("Resources/Textures/DefaultButton.png");
	Unit3Button->SetPosition(1250, Unit1Button->GetPosition().y);
	Unit3Button->SetHeight(500);
	Unit3Button->SetPadding(-10, 0);
	Unit3Button->GetText()->SetText("UNIT 3");
	Unit3Button->SetTextPadding(75, 35);
	Unit3Button->GetImage()->SetAlpha(0.5f);

	buttonExit = new ButtonUI("Resources/Textures/DefaultButton.png");
	buttonExit->SetPosition(-(Unit1Button->GetWidth() / 2) - 150, Unit1Button->GetPosition().y + 500);
	buttonExit->SetHeight(100);
	buttonExit->GetText()->SetText("EXIT");
	buttonExit->GetText()->SetColour(0.0f, 0.0f, 0.0f);
	buttonExit->SetTextPadding(75, 35);
	buttonExit->GetImage()->SetAlpha(0.5f);

	sliderTEST = new SliderUI("Resources/Textures/Green.jpg", "Resources/Textures/blackFILL.png");
	sliderTEST->SetPosition(350, 1000);
	sliderTEST->SetHeight(100);
	sliderTEST->SetValue(0.9f);


	//Unit1 = new Model("Resources/Models/Unit1/figyrk0003.obj");
	//Unit1 = new Model("Resources/Models/Robot_Base_Greybox/Robot_Var_002_Gurran.obj");
	Unit1 = new Model("Resources/Objects/nanosuit/nanosuit.obj");
	Unit1->SetShader(defaultShader);
	Unit1->physicsComponent->SetPosition(glm::vec3(1.0f, -1.0f, -2.5f));
	Unit1->SetWorldScale(0.005f);
	Unit1->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Unit1->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Unit1->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	Unit1->physicsComponent->SetMass(0.0f);

	Unit2 = new Model("Resources/Objects/nanosuit/nanosuit.obj");
	Unit2->SetShader(defaultShader);
	Unit2->physicsComponent->SetPosition(glm::vec3(1.0f, -1.0f, -2.5f));
	Unit2->SetWorldScale(0.004f);
	Unit2->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Unit2->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Unit2->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	Unit2->physicsComponent->SetMass(0.0f);

	Unit3 = new Model("Resources/Objects/nanosuit/nanosuit.obj");
	Unit3->SetShader(defaultShader);
	Unit3->physicsComponent->SetPosition(glm::vec3(1.0f, -1.0f, -2.5f));
	Unit3->SetWorldScale(0.05f);
	Unit3->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Unit3->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Unit3->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	Unit3->physicsComponent->SetMass(0.0f);

	// Lights
	//
	// Make point light
	pointLight = new Light();
	pointLight->SetShader(defaultShader);
	pointLight->renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
	pointLight->renderComponent->SetColour(1.0f, 1.0f, 1.0f);
	pointLight->renderComponent->CanRender(false);
	pointLight->SetWorldPosition(2.0f, 0.0f, -2.5f);
	pointLight->SetWorldScale(0.5f);
	pointLight->lightComponent->SetLightType(LightComponent::Light_Type::POINTLIGHT);
	pointLight->lightComponent->SetColour(glm::vec3(1.0f, 1.0f, 1.0f));
	//

	// Make directional light
	dirLight = new Light(LightComponent::Light_Type::DIRECTIONAL);
	dirLight->lightComponent->SetDirection(glm::vec3(1.0f, -1.0f, 1.0f));
	dirLight->lightComponent->SetColour(glm::vec3(0.3f, 0.3f, 0.3f));
	//

	AddUIObject(titleText);
	AddUIObject(Unit1Button);
	AddUIObject(Unit3Button);
	AddUIObject(Unit2Button);
	AddUIObject(buttonExit);
	//	AddUIObject(sliderTEST);
		///
	AddLightObject(dirLight);
	AddLightObject(pointLight);

	return true;

}

void UnitSelection::Update(const float deltaTime)
{
	//cameraList[0]->SetRotationY(cameraList[0]->Yaw -= deltaTime * 5);	

	float lastPosition = Unit1Button->GetPosition().x;
	Unit1Button->SetPosition(lastPosition += deltaTime * 3000, Unit1Button->GetPosition().y);
	if (Unit1Button->GetPosition().x > (Unit1Button->GetWidth() / 2) + 150) {
		Unit1Button->SetPosition((Unit1Button->GetWidth() / 2) + 150, Unit1Button->GetPosition().y);
	}

	float lastPosition2 = buttonExit->GetPosition().x;
	buttonExit->SetPosition(lastPosition += deltaTime * 3000, buttonExit->GetPosition().y);
	if (buttonExit->GetPosition().x > (buttonExit->GetWidth() / 2) + 150) {
		buttonExit->SetPosition((buttonExit->GetWidth() / 2) + 150, buttonExit->GetPosition().y);
	}

	float lastPosition3 = titleText->GetPosition().y;
	titleText->SetPosition(50, lastPosition3 += deltaTime * 2000);
	if (titleText->GetPosition().y > 100) {
		titleText->SetPosition(50, 100);
	}

	float lastPosition4 = sliderTEST->GetPosition().x;
	sliderTEST->SetPosition(lastPosition4 += deltaTime * 3000, sliderTEST->GetPosition().y);
	if (sliderTEST->GetPosition().x > (sliderTEST->GetWidth() / 2) + 150) {
		sliderTEST->SetPosition((sliderTEST->GetWidth() / 2) + 150, sliderTEST->GetPosition().y);
	}
	sliderTEST->Update(deltaTime);
}

void UnitSelection::FixedUpdate(const float deltaTime)
{
	Unit1->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), Unit1->GetWorldRotationAngle() + 2.0f * deltaTime);
	Unit2->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), Unit2->GetWorldRotationAngle() + 2.0f * deltaTime);
	Unit3->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), Unit3->GetWorldRotationAngle() + 2.0f * deltaTime);
};

void UnitSelection::HandleEvents(SDL_Event events)
{
	if (events.jbutton.button == 2) //x button
	{
		//sceneManager->SwitchScene(new CharacterSelectScene());
	}

	if (Unit1Button->OnHover(events, sceneManager))
	{
		ClearObjects();
		AddObject(Unit1);
		Unit1Button->SetSelected(true);
		Unit1Button->GetImage()->SetScale(1.2f);
		Unit1Button->GetImage()->SetAlpha(1.0f);
		if (events.type == SDL_MOUSEBUTTONDOWN) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				Unit1Button->GetImage()->SetScale(1.1f);
			}
		}
		if (events.type == SDL_MOUSEBUTTONUP) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				if (Unit1Button->GetSelected()) {
					sceneManager->NextScene();
				}
			}
		}
	}
	else
	{
		Unit1Button->SetSelected(false);
		Unit1Button->GetImage()->SetScale(1);
		Unit1Button->GetImage()->SetAlpha(0.5f);
	}

	if (Unit2Button->OnHover(events, sceneManager))
	{
		ClearObjects();
		AddObject(Unit2);
		Unit2Button->SetSelected(true);
		Unit2Button->GetImage()->SetScale(1.2f);
		Unit2Button->GetImage()->SetAlpha(1.0f);
		if (events.type == SDL_MOUSEBUTTONDOWN) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				Unit2Button->GetImage()->SetScale(1.1f);
			}
		}
		if (events.type == SDL_MOUSEBUTTONUP) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				if (Unit2Button->GetSelected()) {
					//	sceneManager->SwitchScene(new TestScene());
				}
			}
		}
	}
	else
	{
		Unit2Button->SetSelected(false);
		Unit2Button->GetImage()->SetScale(1);
		Unit2Button->GetImage()->SetAlpha(0.5f);
	}

	if (Unit3Button->OnHover(events, sceneManager))
	{
		ClearObjects();
		AddObject(Unit3);
		Unit3Button->SetSelected(true);
		Unit3Button->GetImage()->SetScale(1.2f);
		Unit3Button->GetImage()->SetAlpha(1.0f);
		if (events.type == SDL_MOUSEBUTTONDOWN) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				Unit3Button->GetImage()->SetScale(1.1f);
				sceneManager->NextScene();
			}
		}
		if (events.type == SDL_MOUSEBUTTONUP) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				if (Unit3Button->GetSelected()) {
					//sceneManager->SwitchScene(new DemoScene());
				}
			}
		}
	}
	else
	{
		Unit3Button->SetSelected(false);
		Unit3Button->GetImage()->SetScale(1);
		Unit3Button->GetImage()->SetAlpha(0.5f);
	}

	if (buttonExit->OnHover(events, sceneManager))
	{
		buttonExit->SetSelected(true);
		buttonExit->GetImage()->SetScale(1.2f);
		buttonExit->GetImage()->SetAlpha(1.0f);
		if (events.type == SDL_MOUSEBUTTONDOWN) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				buttonExit->GetImage()->SetScale(1.1f);
			}
		}
		if (events.type == SDL_MOUSEBUTTONUP) {
			if (events.button.button == SDL_BUTTON_LEFT)
			{
				if (buttonExit->GetSelected()) {
					sceneManager->SetIsQuit(true);
				}
			}
		}
	}
	else
	{
		buttonExit->SetSelected(false);
		buttonExit->GetImage()->SetScale(1);
		buttonExit->GetImage()->SetAlpha(0.5f);
	}
}

void UnitSelection::HandleStates(const Uint8 *state)
{
	if (state[SDL_SCANCODE_Z]) {
		sceneManager->PreviousScene();
	}

	if (state[SDL_SCANCODE_I]) {
		//	sceneManager->SwitchScene(new TvTGameScene());
	}

	if (state[SDL_SCANCODE_P]) {
		//sceneManager->SwitchScene(new CharacterSelectScene());
	}

	if (state[SDL_SCANCODE_O]) {
		//	sceneManager->SwitchScene(new ShowCaseScene());
	}
}