#include "Player.h"



Player::Player()
{
	PlayingIntro = true;
	///AI stuff
	computerPlayer = false;
	CPUMovementCD = Cooldown(0);
	CPUShootingCD = Cooldown(0);
	//rand = Randomizer();
	///AI stuff ends

	// Make player parts
	base = new ObjectBase("Resources/Objects/nanosuit/nanosuit.obj");
	base->SetWorldPosition(0.0f, 0.0f, 0.0f);
	base->SetWorldScale(0.012f);
	base->renderComponent->SetColour(0.2f, 0.7f, 0.0f);

	

	// Initialize collision component
	collisionComponent = new CollisionComponent();
	collisionComponent->CreateCollisionVolume(CollisionComponent::Collision_Type::BOX, base->renderComponent->getVertexList());
	collisionComponent->SetBoxPadding(glm::vec3(0.4f, 0.4f, 0.4f));

	// Initialize physics componenet
	physicsComponent = new PhysicsComponent();
	physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	physicsComponent->SetMass(50.0f);

	// Set up shader
	projectileShader = new Shader("Engine/Shaders/model.vs", "Engine/Shaders/model.fs");
	//pShader = EngineClass::GetInstance()->GetSceneManager()->GetRenderer()->GetShaderManager()->put(std::string("projectile"), projectileShader);

	// Set direction to team 1 orientation by default
	dir = -1;

	// Set player to target another enemy by default
	isTargeting = false;

	// Set cooldowns
	movementCD = Cooldown(0.0);
	shieldCD = Cooldown(2.0);
	healthIncrementCD = Cooldown(0.1);

	// Set game gamplay status
	out = false;
	canMove = true;

	
	SetStats();
}

Player::~Player()
{
	// TODO: delete everything
}

void Player::AddProjecitleManager(ProjectileManager* pM)
{
	projectileManager = pM;
}

void Player::Update(const float deltaTime)
{

	
	

	// UPDATE TIMERS
	//
	// Update stun timer
	if (playerState == STUN) {
		stunTimer -= deltaTime;
		if (stunTimer <= 0) {
			stunTimer = 0;
			playerState = NORMAL;
		}
	}

	lightComboTimer -= deltaTime;
	if (lightComboTimer <= 0) {
		lightComboTimer = 0;
		lightComboPosition = 0;
	}

	mediumComboTimer -= deltaTime;
	if (mediumComboTimer <= 0) {
		mediumComboTimer = 0;
		mediumComboPosition = 0;
	}

	heavyComboTimer -= deltaTime;
	if (heavyComboTimer <= 0) {
		heavyComboTimer = 0;
		heavyComboPosition = 0;
	}

	specialComboTimer -= deltaTime;
	if (specialComboTimer <= 0) {
		specialComboTimer = 0;
		specialComboPosition = 0;
	}
	//

	
}

void Player::FixedUpdate(const float deltaTime) {

	
	// Update collision and physics
	physicsComponent->Update(deltaTime);
	SetWorldPosition(physicsComponent->GetPosition());
	collisionComponent->Update(GetWorldPosition());

	if (playerState != STUN) {
		physicsComponent->SetVelocity(glm::vec3(0.0f, physicsComponent->GetVelocity().y, 0.0f));
	}

	// Update player model
	UpdateModel(deltaTime);
	

	

	// Update function from child
	InheritedUpdate(deltaTime);
}

void Player::HandleEvents(SDL_Event events) ///THIS HAS BEEN BANNED IN ACCORDENCE WITH THE NEW CONTROLLER FUNCTIONALITY. USE HandleControllerEvents instead
{
	// Child events
	InheritedHandleEvents(events); ///we will also need to ban this function, but no one uses it anyways
}

void Player::HandleStates(const Uint8 *state)
{
	InheritedHandleStates(state);
}

void Player::Movement(PLAYERMOVEMENT movement, const float deltaTime)
{
	if (playerState == NORMAL) {

		float moveMod = 1;

		if (worldPosition.y > 0.1f) {
			moveMod = 0.5f;
		}
		if (movement == FORWARD) {
			if (!out) {
				physicsComponent->SetVelocity(glm::vec3(physicsComponent->GetVelocity().x, physicsComponent->GetVelocity().y, (-moveSpeed * moveMod) * deltaTime * 500 * dir));
			}
			//base->SetLocalRotation(glm::vec3(1.0f, 0.0f, 0.0f), -0.12f);
		}
		if (movement == BACKWARD) {
			if (!out) {
				physicsComponent->SetVelocity(glm::vec3(physicsComponent->GetVelocity().x, physicsComponent->GetVelocity().y, (moveSpeed * moveMod) * deltaTime * 500 * dir));
			}
			//base->SetLocalRotation(glm::vec3(1.0f, 0.0f, 0.0f), 0.2f);
		}
		if (movement == RIGHT) {
			if (!out) {
				physicsComponent->SetVelocity(glm::vec3((moveSpeed * moveMod) * deltaTime * 500 * dir, physicsComponent->GetVelocity().y, physicsComponent->GetVelocity().z));
			}
			//base->SetLocalRotation(glm::vec3(0.0f, 0.0f, 1.0f), -0.2f);
		}
		if (movement == LEFT) {
			if (!out) {
				physicsComponent->SetVelocity(glm::vec3((-moveSpeed * moveMod) * deltaTime * 500 * dir, physicsComponent->GetVelocity().y, physicsComponent->GetVelocity().z));
			}
			//base->SetLocalRotation(glm::vec3(0.0f, 0.0f, 1.0f), 0.2f);
		}
	}
}

void Player::UpdateModel(const float deltaTime)
{
	
	
}

void Player::ResetModel() {
	// Set rotations back to normal

}

void Player::SetStats() {
	shieldHealth = maxHealth;
	moveSpeed = 2.0f;
	specialMeter = 0;
}

void Player::SetEnemyTeam(Player* player1, Player* player2) {
	enemyTeam = { player1, player2 };
	SetTarget(player1->GetWorldPosition());
}

void Player::SetTarget(glm::vec3 targetPlayer) {
	targetedPlayer = targetPlayer;
}

void Player::SetTarget(int target) {
	currentTarget = target;
}

void Player::SetTargetColour(glm::vec3 colour) {
	targetColour = colour;

}

void Player::SetPlayerTeam(PLAYERTEAM pT) {
	playerTeam = pT;
	if (playerTeam == PLAYERTEAM::TEAM1) {
		dir = 1;
	}
	else if (playerTeam == PLAYERTEAM::TEAM2) {
		dir = -1;
	}
}

void Player::Hit(Projectile* projectile) {
	
		physicsComponent->AddForce(projectile->GetForce());
		
	
}

void Player::Stun() {
	ComboReset();
	stunTimer = stunTimerSet;
	playerState = STUN;
	ResetModel();
}

void Player::Stun(float stunTime) {
	stunTimer = stunTime;
	playerState = STUN;
	ResetModel();
}

void Player::Block() {
	if (playerState == PLAYERSTATES::NORMAL) {
		if (shieldHealth > 0) {
			playerState = BLOCK;
			physicsComponent->SetVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
		}
		else if (shieldHealth <= 0) {
			playerState = NORMAL;
		}
		ResetModel();
	}
}

void Player::StopBlock() {
	if (playerState == BLOCK) {
		playerState = NORMAL;
		ResetModel();
	}
}

void Player::ComboReset() {
	lightComboTimer = 0;
	lightComboPosition = 0;
	mediumComboTimer = 0;
	mediumComboPosition = 0;
	heavyComboTimer = 0;
	heavyComboPosition = 0;
	specialComboTimer = 0;
	specialComboPosition = 0;
}

void Player::Jump() {
	if (canJump == true)
	{
		physicsComponent->AddForce(glm::vec3(0.0f, 110.0f, 0.0f));
		canJump = false;
	}
}

void Player::SwitchTarget() {
	if (currentTarget == 0) {
		currentTarget = 1;
	}
	else if (currentTarget == 1) {
		currentTarget = 0;
	}
}

void Player::EnableTarget() {
	if (isTargeting) {
		isTargeting = false;
	}
	else if (!isTargeting) {
		isTargeting = true;
	}
}

void Player::Render(Shader* shader, const double _interpolation)
{
	// Account for interpolation
	glm::mat4 interpolatedMatrix;
	interpolatedMatrix = worldModelMatrix * (float)_interpolation + previousWorldModelMatrix * (1.0f - (float)_interpolation);

	

	// Don't interpolate on the first render 
	if (firstRender == true) {
		interpolatedMatrix = worldModelMatrix;
	}

	shader->setMat4("model", interpolatedMatrix * localModelMatrix * base->GetWorldModelMatrix() * base->GetLocalModelMatrix() * base->model->GetWorldModelMatrix() * base->model->GetLocalModelMatrix());
	base->Render(shader, _interpolation);

	

}

void Player::SetPlayerNumber(PLAYERNUMBER pN) {
	playerNumber = pN;
	int x = 0;
	
}




///learning block
/// negative numbers on the z axis are forwrds for both teams. positive numbers are backwards
/// in the x axis it is different for each team
/// negative numbers are left and positive numbers are right for team 1
/// positive numbers are left for team 2 and positive numbers are right

void Player::BoundsCheckT2()
{
	////std::cout << worldPosition.x << " " << worldPosition.z << std::endl;
	//if (worldPosition.z > -1) { //too close to the front
	//	playerInput->controllerState.at(2) = 3;
	//}
	//if (worldPosition.z < -4.2) { //too close to the back
	//	playerInput->controllerState.at(2) = -3;
	//}
	//if (worldPosition.x < -4) { //too close to the front
	//	playerInput->controllerState.at(1) = -3;
	//}
	//if (worldPosition.x > 4) { //too close to the front
	//	playerInput->controllerState.at(1) = 3;
	//}
}

void Player::BoundsCheckT1()
{
	////std::cout << worldPosition.x << " " << worldPosition.z << std::endl;
	//if (worldPosition.z < 1) { //too close to the front
	//	playerInput->controllerState.at(2) = 3;
	//}
	//if (worldPosition.z > 4.2) { //too close to the back
	//	playerInput->controllerState.at(2) = -3;
	//}
	//if (worldPosition.x < -4) { //too close to the front
	//	playerInput->controllerState.at(1) = 3;
	//}
	//if (worldPosition.x > 4) { //too close to the front
	//	playerInput->controllerState.at(1) = -3;
	//}

}

void Player::HandleControllerEvents() {
	
}