#include "Game1.h"


Game1::Game1()
{
}

Game1::~Game1()
{
}

bool Game1::Initialize()
{
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
	pointLight->renderComponent->SetColour(0.0f, 0.0f, 1.0f);
	pointLight->renderComponent->CanRender(false);
	// Set position and scale of object
	pointLight->SetWorldPosition(0.0f, 5.0f, 0.0f);
	pointLight->SetWorldScale(0.5f);
	// Set what type of light and what colour this object emits
	pointLight->lightComponent->SetColour(glm::vec3(1.0f, 2.0f, 1.0f));
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
	player1->SetShader(defaultShader);
	player1->SetWorldPosition(glm::vec3(-2.0f, 0.0f, 3.0f));
	player1->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER1);
	player1->SetPlayerTeam(Player::PLAYERTEAM::TEAM1);
	
//	player1->GetPlayerInput()->AddAnyController();
	player1->AddProjecitleManager(projectileManager);

	// Player 2
	player2 = new BaseUnit_0();
//	player2->dialogue.channel = 2;
	player2->SetShader(defaultShader);
	player2->SetWorldPosition(glm::vec3(2.0f, 0.0f, 3.0f));
	player2->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER2);
	player2->SetPlayerTeam(Player::PLAYERTEAM::TEAM1);
//	player2->GetPlayerInput()->AddAnyController();
	player2->AddProjecitleManager(projectileManager);

	// Player 3
	player3 = new BaseUnit_0();
	//player3->dialogue.channel = 3;
	player3->SetShader(defaultShader);
	player3->SetWorldPosition(glm::vec3(2.0f, 0.0f, -3.0f));
	player3->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER3);
	player3->SetPlayerTeam(Player::PLAYERTEAM::TEAM2);
	//player3->GetPlayerInput()->AddAnyController();
	player3->AddProjecitleManager(projectileManager);

	// Player 4
	player4 = new BaseUnit_0();
	//player4->dialogue.channel = 4;
	player4->SetShader(defaultShader);
	player4->SetWorldPosition(glm::vec3(-2.0f, 0.0f, -3.0f));
	player4->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER4);
	player4->SetPlayerTeam(Player::PLAYERTEAM::TEAM2);
//	player4->GetPlayerInput()->AddAnyController();
	player4->AddProjecitleManager(projectileManager);

	// Enemy Target set up
	player1->SetEnemyTeam(player3, player4);
	player2->SetEnemyTeam(player4, player3);
	player3->SetEnemyTeam(player1, player2);
	player4->SetEnemyTeam(player2, player1);

	// Arena
	floor = new Cube();
	floor->SetShader(defaultShader);
	floor->renderComponent->SetColour(0.1f, 0.1f, 0.1f);
	floor->physicsComponent->SetPosition(glm::vec3(0.0f, -1.0f, 0.0f));
	floor->SetWorldScale(11.0f, 1.0f, 11.0f);
	floor->physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::STATIC);
	floor->physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	floor->physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	floor->physicsComponent->SetMass(0.0f);

	map = new Map1();
	map->tag = "floor";
	map->SetShader(defaultShader);
	map->SetWorldPosition(glm::vec3(0.0f, -1.0f, 0.0f));
	map->physicsComponent->SetMass(0.0f);
	projectileManager->AddEnvironment(floor);
	
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

	// add objects and lights to their lists
	AddObject(player1);
	AddObject(player2);
	AddObject(player3);
	AddObject(player4);
//	AddObject(floor);
	AddObject(map);

	AddObject(projectileManager->GetProjectileRenderer());
	AddLightObject(dirLight);
	AddLightObject(pointLight);

	// update phyics list
	PhysicsEngine::GetInstance()->AddObjectList(objectList);

	// Add players to the projectile manager
	projectileManager->AddPlayer(player1);
	projectileManager->AddPlayer(player2);
	projectileManager->AddPlayer(player3);
	projectileManager->AddPlayer(player4);

	playerList.push_back(player1);
	playerList.push_back(player2);
	playerList.push_back(player3);
	playerList.push_back(player4);

	collisionObjectList.push_back(map);

	return true;
}

void Game1::Update(const float deltaTime)
{
//	/*cameraList[0]->Position = glm::vec3(player1->GetWorldPosition().x, player1->GetWorldPosition().y + 1, player1->GetWorldPosition().z);
//	player1->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-cameraList[0]->Yaw));
//*/
	this->deltaTime = deltaTime;
	for (int i = 0; i < playerList.size(); i++)
	{
		for (int j = 0; j < collisionObjectList.size(); j++) {
			if (PhysicsEngine::isColliding(playerList[i]->collisionComponent, collisionObjectList[j]->collisionComponent))
			{
				if (playerList[i]->canJump == false && collisionObjectList[j]->tag == "floor")
				{
					playerList[i]->canJump = true;
				}
				
			}
		}
	} 
	projectileManager->Update(deltaTime);

}

void Game1::FixedUpdate(const float deltaTime)
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

void Game1::HandleEvents(SDL_Event events)
{
	// PLAYER
	// Light Attack
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_LEFT:
			// Create projectile
			// LightAttack returns a projectile
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
		if (events.key.keysym.sym == SDLK_UP) {
			player1->Jump();
		}

		if (events.key.keysym.sym == SDLK_DOWN) {
			std::vector<Projectile*> p = player1->MediumAttack();
			// Add it to the projectile manager if the returned projectile is not null
			if (p.size() > 0) {
				for  (Projectile* subP : p) {
					projectileManager->AddProjectile(subP);
				}
			}
		}

		if (events.key.keysym.sym == SDLK_RIGHT) {
			rotTest += 0.261799;
			player1->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), rotTest); 
		}

		if (events.key.keysym.sym == SDLK_RCTRL) {
			std::vector<Projectile*> p = player1->SpecialAttack();
			// Add it to the projectile manager if the returned projectile is not null
			if (p.size() > 0) {
				for  (Projectile* subP : p) {
					projectileManager->AddProjectile(subP);
				}
			}
		}

		if (events.key.keysym.sym == SDLK_o) {
			player1->SwitchTarget();
		}

		if (events.key.keysym.sym == SDLK_i) {
			player1->EnableTarget();
		}
	}

	if (events.type == SDL_MOUSEMOTION) {
		cameraList[0]->ProcessMouseMovement((float)events.motion.x, (float)events.motion.y);
		//player1->UpdateModel(cameraList[0]);
	}
	// Call player handle events
	// only player 1 for now to test
	player1->HandleEvents(events);
	player2->HandleEvents(events);
	player3->HandleEvents(events);
	player4->HandleEvents(events);
}

void Game1::HandleStates(const Uint8 *state)
{
	// Call player handle states
	// Only player 1 for now to test
	player1->HandleStates(state);
	player2->HandleStates(state);
	player3->HandleStates(state);
	player4->HandleStates(state);


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
		player1->Movement(Player::PLAYERMOVEMENT::FORWARD, fixedDeltaTime);
	}
	if (state[SDL_SCANCODE_S]) {
		player1->Movement(Player::PLAYERMOVEMENT::BACKWARD, fixedDeltaTime);
	}
	if (state[SDL_SCANCODE_D]) {
		player1->Movement(Player::PLAYERMOVEMENT::RIGHT, fixedDeltaTime);
	}
	if (state[SDL_SCANCODE_A]) {
		player1->Movement(Player::PLAYERMOVEMENT::LEFT, fixedDeltaTime);
	}

	// Reload Scene
	if (state[SDL_SCANCODE_Z]) {
		sceneManager->SwitchScene(new Game1());
	}

	if (state[SDL_SCANCODE_E]) {
		player1->Block();
		player2->Block();
		player3->Block();
		player4->Block();
	}
	else {
		player1->StopBlock();
		player2->StopBlock();
		player3->StopBlock();
		player4->StopBlock();
	}

	// ENABLE OR DISABLE FULLSCREEN WITH V AND B
	// ENABLE OR DISABLE SPLITSCREEN WITH N AND M
}