#include "DreamZEngineDemo.h"


DreamZEngineDemo::DreamZEngineDemo()
{
}

DreamZEngineDemo::~DreamZEngineDemo()
{
}

bool DreamZEngineDemo::Initialize()
{
	title = "DreamZEngineDemo";
	// Make reference to the scene manager
	sceneManager = EngineClass::GetInstance()->GetSceneManager();

	// Set screen options
	sceneManager->EnableSplitscreen(false);
	sceneManager->EnableFullscreen(false);
	sceneManager->ShowFPS(true);
	sceneManager->CaptureMouse(false);

	// Set the options for the first camera
	cameraList[0]->Position = glm::vec3(0.0f, 6.0f, 10.0f);
	cameraList[0]->SetRotationX(-25.0f);
	

	// Load shaders
	defaultShader = new Shader("Engine/Shaders/model.vs", "Engine/Shaders/model.fs");
	skyboxShader = new Shader("Engine/Shaders/skybox.vs", "Engine/Shaders/skybox.fs");

	// Put shaders into shader manager
	

	// Lights
	//
	// Initialize
	pointLight = new Light(LightComponent::Light_Type::POINTLIGHT);
	// Set which shader this object is using
	pointLight->SetShader(defaultShader);
	// Set type and colour of object's mesh
	pointLight->renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
	pointLight->renderComponent->SetColour(1.0f, 0.0f, 0.0f);
	pointLight->renderComponent->CanRender(false);
	// Set position and scale of object
	pointLight->SetWorldPosition(-4.0f, 5.0f, 0.0f);
	pointLight->SetWorldScale(0.5f);
	// Set what type of light and what colour this object emits
	pointLight->lightComponent->SetColour(glm::vec3(0.0f, 4.0f, 0.0f));
	//	

	// Make directional light
	dirLight = new Light(LightComponent::Light_Type::DIRECTIONAL);
	dirLight->lightComponent->SetDirection(glm::vec3(1.0f, -1.0f, 1.0f));

	// Make Projectile Manager
	projectileManager = new ProjectileManager();

	// Make Players
	//
	// Player 1
	player1 = new BaseUnit_0();
	//player1->dialogue.channel = 1;
	player1->tag = "1";
	player1->SetShader(defaultShader);
	player1->SetWorldPosition(glm::vec3(-3.0f, 0.0f, 2.0f));
	
	
//	player1->GetPlayerInput()->AddAnyController();
	player1->AddProjecitleManager(projectileManager);

	

	

	// Arena
	floor = new Cube();
	floor->SetShader(defaultShader);
	floor->tag = "floor";
	floor->renderComponent->SetColour(0.1f, 0.1f, 0.1f);
	floor->physicsComponent->SetPosition(glm::vec3(0.0f, -1.0f, 0.0f));
	floor->SetWorldScale(21.0f, 1.0f, 11.0f);
	floor->physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	floor->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	floor->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::VERY_ELASTIC);
	floor->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	floor->physicsComponent->SetMass(0.0f);


	Demo1Cube = new Cube();
	Demo1Cube->SetShader(defaultShader);
	Demo1Cube->tag = "demo1";
	Demo1Cube->renderComponent->SetColour(0.1f, 0.1f, 1.1f);
	Demo1Cube->physicsComponent->SetPosition(glm::vec3(-4.0f, 0.0f, 0.0f));
	Demo1Cube->SetWorldScale(1.0f, 0.1f, 1.0f);
	Demo1Cube->physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	Demo1Cube->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Demo1Cube->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Demo1Cube->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	Demo1Cube->physicsComponent->SetMass(0.0f);

	Demo2Cube = new Cube();
	Demo2Cube->SetShader(defaultShader);
	Demo2Cube->tag = "demo2";
	Demo2Cube->renderComponent->SetColour(0.1f, 0.1f, 1.1f);
	Demo2Cube->physicsComponent->SetPosition(glm::vec3(-2.0f, 0.0f, 0.0f));
	Demo2Cube->SetWorldScale(1.0f, 0.1f, 1.0f);
	Demo2Cube->physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	Demo2Cube->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Demo2Cube->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Demo2Cube->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	Demo2Cube->physicsComponent->SetMass(0.0f);

	Demo3Cube = new Cube();
	Demo3Cube->SetShader(defaultShader);
	Demo3Cube->tag = "demo3";
	Demo3Cube->renderComponent->SetColour(0.1f, 0.1f, 1.1f);
	Demo3Cube->physicsComponent->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	Demo3Cube->SetWorldScale(1.0f, 0.1f, 1.0f);
	Demo3Cube->physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	Demo3Cube->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Demo3Cube->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Demo3Cube->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	Demo3Cube->physicsComponent->SetMass(0.0f);

	Demo4Cube = new Cube();
	Demo4Cube->SetShader(defaultShader);
	Demo4Cube->tag = "demo4";
	Demo4Cube->renderComponent->SetColour(1.1f, 0.1f, 1.1f);
	Demo4Cube->physicsComponent->SetPosition(glm::vec3(2.0f, 0.0f, 0.0f));
	Demo4Cube->SetWorldScale(1.0f, 0.1f, 1.0f);
	Demo4Cube->physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	Demo4Cube->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Demo4Cube->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Demo4Cube->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	Demo4Cube->physicsComponent->SetMass(0.0f);

	Demo5Cube = new Cube();
	Demo5Cube->SetShader(defaultShader);
	Demo5Cube->tag = "demo5";
	Demo5Cube->renderComponent->SetColour(2.1f, 0.1f, 1.1f);
	Demo5Cube->physicsComponent->SetPosition(glm::vec3(4.0f, 0.0f, 0.0f));
	Demo5Cube->SetWorldScale(1.0f, 0.1f, 1.0f);
	Demo5Cube->physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	Demo5Cube->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	Demo5Cube->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	Demo5Cube->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	Demo5Cube->physicsComponent->SetMass(0.0f);

	map = new Map1();
	map->tag = "floor";
	map->SetShader(defaultShader);
	map->SetWorldPosition(glm::vec3(0.0f, -1.0f, 0.0f));
	map->physicsComponent->SetMass(0.0f);
	projectileManager->AddEnvironment(floor);
	
	ball = new Ball();
	ball->tag = "ball";
	ball->SetShader(defaultShader);
	ball->SetWorldPosition(glm::vec3(0.0f, 0.0f, 1.0f));
	ball->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	ball->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::ELASTIC);
	ball->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);

	ball2 = new Ball();
	ball2->tag = "ball";
	ball2->SetShader(defaultShader);
	ball2->SetWorldPosition(glm::vec3(0.0f, 0.0f, 1.0f));
	ball2->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	ball2->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::VERY_ELASTIC);
	ball2->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);

	
	// UI
	scoreBoard = new TextUI();
	//titleText->SetFont("Resources/Fonts/ka1.ttf");
	scoreBoard->SetText(std::to_string(Team1Score) + ":" + std::to_string(Team2Score));
	scoreBoard->SetColour(1.0, 1.0f, 1.0f);
	scoreBoard->SetSize(0.8f);
	scoreBoard->SetSpacing(9.0f);
	scoreBoard->SetPosition(100, -100);

	sliderTEST = new SliderUI("Resources/Textures/Green.jpg", "Resources/Textures/blackFILL.png");
	sliderTEST->SetPosition(350, 1000);
	sliderTEST->SetHeight(100);
	sliderTEST->SetValue(chargeValue);

	// Make skybox, load its textures, set properties, and give to the renderer
	skybox = new Skybox();
	std::vector<std::string> faces;
	faces.push_back("Resources/Skybox/Skyboxes/right.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/left.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/top.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/bottom.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/back.jpg");
	faces.push_back("Resources/Skybox/Skyboxes/front.jpg");
	skybox->LoadTextures(faces);
	skybox->SetShader(skyboxShader);

	// add objects and lights to their lists
	AddObject(player1);
	
	AddObject(floor);
	AddObject(Demo1Cube);
	AddObject(Demo2Cube);
	AddObject(Demo3Cube);
	AddObject(Demo4Cube);
	AddObject(Demo5Cube);
	//AddObject(goal);
	//AddObject(map);

	
		
		
		

		
	AddObject(projectileManager->GetProjectileRenderer());
	AddLightObject(dirLight);
	AddLightObject(pointLight);
	AddUIObject(scoreBoard);
	AddUIObject(sliderTEST);

	// update phyics list
	PhysicsEngine::GetInstance()->AddObjectList(objectList);

	// Add players to the projectile manager
	projectileManager->AddPlayer(player1);
	

	playerList.push_back(player1);
	

	collisionObjectList.push_back(floor);
	collisionObjectList.push_back(Demo1Cube);
	collisionObjectList.push_back(Demo2Cube);
	collisionObjectList.push_back(Demo3Cube);
	collisionObjectList.push_back(Demo4Cube);
	collisionObjectList.push_back(Demo5Cube);

	return true;
}

void DreamZEngineDemo::Update(const float deltaTime)
{


	this->deltaTime = deltaTime;
	
	
	
	if (!EngineClass::GetInstance()->GetFirstLoad())
	{
		CollsionCheck();
		projectileManager->Update(deltaTime);

		projectileManager->Update(deltaTime);

		DemoState();
	}
	sceneManager->DebugText(demoText.first);
	sceneManager->DebugText(demoText.second);
	sceneManager->DebugText(demoText.third);
	sceneManager->DebugText(demoText.fourth);
	sceneManager->DebugText(demoText.fifth);
	sceneManager->DebugText(demoText.sixth);
	sceneManager->DebugText(demoText.seventh);
}

void DreamZEngineDemo::FixedUpdate(const float deltaTime)
{

	// Update object list for physics
	PhysicsEngine::GetInstance()->AddObjectList(objectList);

	// Update physics and projectile manager
	PhysicsEngine::GetInstance()->Update(deltaTime);
	projectileManager->FixedUpdate(deltaTime);

	// Update projectiles in projectile manager
	if (projectileManager->GetProjectileList().size() != NULL) {
		for (size_t i = 0; i < projectileManager->GetProjectileList().size(); ++i) {
			if (projectileManager->GetProjectileList().at(i)->deleted) {
				projectileManager->RemoveProjectile(projectileManager->GetProjectileList().at(i));
			}
		}
	}
}

void DreamZEngineDemo::HandleEvents(SDL_Event events)
{
	// PLAYER
	// Light Attack
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_LEFT:
			
			std::vector<Projectile*> p = player1->LightAttack();
			// Add it to the projectile manager if the returned projectile is not null
			if (p.size() > 0) {
				for  (Projectile* subP : p) {
					projectileManager->AddProjectile(subP);
				}
			}
			break;
		}
	}
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		DemoKeyCheck(events);
		
		
		
	}
	if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			std::vector<Projectile*> p = player1->LightAttack();
			// Add it to the projectile manager if the returned projectile is not null
			if (p.size() > 0) {
				for (Projectile* subP : p) {
					projectileManager->AddProjectile(subP);
				}
			}
		}
	}

	if (events.type == SDL_MOUSEMOTION) {
		cameraList[0]->ProcessMouseMovement((float)events.motion.x, (float)events.motion.y);
		//player1->UpdateModel(cameraList[0]);
	}
	// Call player handle events
	// only player 1 for now to test
	player1->HandleEvents(events);
	
}

void DreamZEngineDemo::HandleStates(const Uint8 *state)
{
	// Call player handle states
	// Only player 1 for now to test
	player1->HandleStates(state);
	

	//movement based on camera lookat
	/*if (state[SDL_SCANCODE_W]) {
		player1->Movement(Player::PLAYERMOVEMENT::FORWARD, cameraList[0]);
	}
	if (state[SDL_SCANCODE_S]) {
		player1->Movement(Player::PLAYERMOVEMENT::BACKWARD,  cameraList[0]);
	}
	if (state[SDL_SCANCODE_D]) {
		player1->Movement(Player::PLAYERMOVEMENT::RIGHT,  cameraList[0]);
	}
	if (state[SDL_SCANCODE_A]) {
		player1->Movement(Player::PLAYERMOVEMENT::LEFT,  cameraList[0]);
	}*/

	// Player movement
	// Only player 1 for now to test
	if (state[SDL_SCANCODE_W]) {
		player1->Movement(Player::PLAYERMOVEMENT::FORWARD, -fixedDeltaTime);
	}
	if (state[SDL_SCANCODE_S]) {
		player1->Movement(Player::PLAYERMOVEMENT::BACKWARD, -fixedDeltaTime);
	}
	if (state[SDL_SCANCODE_D]) {
		player1->Movement(Player::PLAYERMOVEMENT::RIGHT, -fixedDeltaTime);
	}
	if (state[SDL_SCANCODE_A]) {
		player1->Movement(Player::PLAYERMOVEMENT::LEFT, -fixedDeltaTime);
	}

	// Reload Scene
	if (state[SDL_SCANCODE_Z]) {
		sceneManager->SwitchScene(new DreamZEngineDemo());
	}

	

	
}

void DreamZEngineDemo::CollsionCheck()
{
	for (int i = 0; i < playerList.size(); i++)
	{
		for (int j = 0; j < collisionObjectList.size(); j++) {

			if (playerList[i]->canJump == false && collisionObjectList[j]->tag == "floor")
			{
				if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
				{
					playerList[i]->canJump = true;
				}
			}
			if (playerList[i]->tag == "1" && collisionObjectList[j]->tag == "demo1")
			{
				if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
				{
					collisionObjectList[j]->renderComponent->SetColour(1.1f, 0.1f, 0.1f);
					playerList[i]->canJump = true;
					demoEnum = DEMO1;
					if (Demo1Checked == false)
					{
						AddObject(ball);
						AddObject(ball2);
						Demo1Checked = true;
					}
				}
				else {
					collisionObjectList[j]->renderComponent->SetColour(0.1f, 0.1f, 1.1f);
					
					
				}
			}else if (playerList[i]->tag == "1" && collisionObjectList[j]->tag == "demo2")
			{
				if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
				{
					collisionObjectList[j]->renderComponent->SetColour(1.1f, 0.1f, 0.1f);
					playerList[i]->canJump = true;
					demoEnum = DEMO2;
					
				}
				else { collisionObjectList[j]->renderComponent->SetColour(0.1f, 0.1f, 1.1f); }
			}else if (playerList[i]->tag == "1" && collisionObjectList[j]->tag == "demo3")
			{
				if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
				{
					collisionObjectList[j]->renderComponent->SetColour(1.1f, 0.1f, 0.1f);
					playerList[i]->canJump = true;
					demoEnum = DEMO3;
					
				}
				else { collisionObjectList[j]->renderComponent->SetColour(0.1f, 0.1f, 1.1f); }
			}else if (playerList[i]->tag == "1" && collisionObjectList[j]->tag == "demo4")
			{
				if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
				{
					collisionObjectList[j]->renderComponent->SetColour(1.1f, 0.1f, 0.1f);
					playerList[i]->canJump = true;
					demoEnum = DEMO4;
					
				}
				else { collisionObjectList[j]->renderComponent->SetColour(0.1f, 0.1f, 1.1f); }
			}else if (playerList[i]->tag == "1" && collisionObjectList[j]->tag == "demo5")
			{
				if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
				{
					collisionObjectList[j]->renderComponent->SetColour(1.1f, 0.1f, 0.1f);
					playerList[i]->canJump = true;
					demoEnum = DEMO5;
					
				}
				else { collisionObjectList[j]->renderComponent->SetColour(0.1f, 0.1f, 1.1f); }
			}
			else { demoEnum = DEFAULT; }

		}
	}
}

void DreamZEngineDemo::DemoState()
{
	switch (demoEnum)
	{
	case DEFAULT:scoreBoard->SetText("WELCOME TO THE DEMO");
		demoText.first	= "Step On A Tile To Load a Demo";
		demoText.second = "Each Tile Will Have Unique Key Bindings";
		demoText.third	= "Press Z at anytime to Restart The Demo";
		demoText.fourth = "Press space for sound effect";
		demoText.fifth	= "";
		demoText.sixth	= "";
		demoText.seventh= "";
			break;			
	case DEMO1:scoreBoard->SetText("DEMO1 - Physics");
		demoText.first = "Two Balls With The Same Mass But Different Elasticity";
		demoText.second = "Current Impulse: " + std::to_string(demoImpulse)  ;
		demoText.third	= "Press 'Y' To Add Impulse to Ball 1 and 2";
		demoText.fourth = "Press 'U' To Add Impulse to Ball 1";
		demoText.fifth = "Press 'I' To Add Impulse to Ball 2";
		demoText.sixth = "Press 'O' To Increase Impulse Force";
		demoText.seventh = "Press 'P' To Decrease Impulse Force"; 
		break;
	case DEMO2:scoreBoard->SetText("DEMO2");
		break;
	case DEMO3:scoreBoard->SetText("DEMO3");
		break;
	case DEMO4:scoreBoard->SetText("DEMO4");
		break;
	case DEMO5:scoreBoard->SetText("DEMO5");
		break;
	}
		
	float lastPosition3 = scoreBoard->GetPosition().y;
	scoreBoard->SetPosition(50, lastPosition3 += deltaTime * 2000);
	if (scoreBoard->GetPosition().y > 100) {
		scoreBoard->SetPosition(750, 100);
	}

	
}

void DreamZEngineDemo::DemoKeyCheck(SDL_Event events)
{
	if (events.key.keysym.sym == SDLK_SPACE) {
		player1->Jump();
		//ball->Bounce();
	}
	if (events.key.keysym.sym == SDLK_y) {
		switch (demoEnum)
		{
		case DEFAULT:
			break;
		case DEMO1:ball->Bounce(demoImpulse);
			ball2->Bounce(demoImpulse);
			break;
		case DEMO2:scoreBoard->SetText("DEMO2");
			break;
		case DEMO3:scoreBoard->SetText("DEMO3");
			break;
		case DEMO4:scoreBoard->SetText("DEMO4");
			break;
		case DEMO5:scoreBoard->SetText("DEMO5");
			break;
		}
	}
	if (events.key.keysym.sym == SDLK_u) {
		switch (demoEnum)
		{
		case DEFAULT:
			break;
		case DEMO1:ball->Bounce(demoImpulse);
			break;
		case DEMO2:scoreBoard->SetText("DEMO2");
			break;
		case DEMO3:scoreBoard->SetText("DEMO3");
			break;
		case DEMO4:scoreBoard->SetText("DEMO4");
			break;
		case DEMO5:scoreBoard->SetText("DEMO5");
			break;
		}
	}
	if (events.key.keysym.sym == SDLK_i) {
		switch (demoEnum)
		{
		case DEFAULT:
			break;
		case DEMO1:ball2->Bounce(demoImpulse);
			
			break;
		case DEMO2:scoreBoard->SetText("DEMO2");
			break;
		case DEMO3:scoreBoard->SetText("DEMO3");
			break;
		case DEMO4:scoreBoard->SetText("DEMO4");
			break;
		case DEMO5:scoreBoard->SetText("DEMO5");
			break;
		}
	}
	if (events.key.keysym.sym == SDLK_o) {
		switch (demoEnum)
		{
		case DEFAULT:
			break;
		case DEMO1:demoImpulse += 10.0;
			break;
		case DEMO2:scoreBoard->SetText("DEMO2");
			break;
		case DEMO3:scoreBoard->SetText("DEMO3");
			break;
		case DEMO4:scoreBoard->SetText("DEMO4");
			break;
		case DEMO5:scoreBoard->SetText("DEMO5");
			break;
		}
	}
	if (events.key.keysym.sym == SDLK_p) {
		switch (demoEnum)
		{
		case DEFAULT:
			break;
		case DEMO1:demoImpulse -= 10.0;
			break;
		case DEMO2:scoreBoard->SetText("DEMO2");
			break;
		case DEMO3:scoreBoard->SetText("DEMO3");
			break;
		case DEMO4:scoreBoard->SetText("DEMO4");
			break;
		case DEMO5:scoreBoard->SetText("DEMO5");
			break;
		}
	}

}
