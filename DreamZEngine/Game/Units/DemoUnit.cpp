#include "DemoUnit.h"


DemoUnit::DemoUnit() {
	base = new UnitBase("Resources/Objects/test/test.obj");
	base->SetWorldPosition(0.0f, 0.0f, 0.0f);
	base->SetWorldScale(0.5f);
	base->renderComponent->SetColour(0.2f, 0.7f, 0.0f);

//	ring->renderComponent->SetColour(0.0f, 1.0f, 0.0f);

	/*shootEffect = new ParticleSystem(EngineClass::GetInstance()->GetSceneManager()->GetRenderer()->GetShaderManager(), glm::vec3(0.0f, 1.0f, 0.0f));
	EngineClass::GetInstance()->GetSceneManager()->GetCurrentScene()->AddObject(shootEffect);

	dialogue = PlayerDialogue(2);
	dialogue.LoadPlayerDialogue("Resources/Audio/OkiCaeliAudio.txt");*/

	SetStats();
}

DemoUnit::~DemoUnit() {

}

std::vector<Projectile*> DemoUnit::LightAttack()
{
	std::vector<Projectile*> projectiles;

	if (playerState == NORMAL && lightComboTimer <= 0) {
		lightComboTimer = 0.3f;

		Projectile* p = new Projectile(glm::vec3(GetWorldPosition().x, GetWorldPosition().y, GetWorldPosition().z - collisionComponent->GetBoundingBox().r.z * 2.0f * GetWorldScale().z * dir), targetAngle, dir);
		p->SetImpulseForce(glm::vec3(0.0f, 0.0f, 180.0f));
		p->SetActingForce(glm::vec3(0.0f, 0.0f, 0.0f));
		p->SetKnockbackForce(glm::vec3(0.0f, 25.0f, 25.0f));
		p->SetStunTime(0.2f);
		p->SetDamage(5);
		p->SetElement(WIND);
		p->SetMesh(PROJECTILE_MESH::NORM_WIND);
		p->SetLifetime(0.5f);
		projectiles.push_back(p);
		return projectiles;
	}

	/*
	if (playerState == NORMAL && lightComboPosition == 0 && playerState != BLOCK && playerState != STUN) {

	if (worldPosition.y > 0.1) {
	physicsComponent->SetVelocity(glm::vec3(0, 5, 0));
	}

	lightComboTimer = 0.5f;
	lightComboPosition++;

	Projectile* p = new Projectile(glm::vec3(GetWorldPosition().x, GetWorldPosition().y, GetWorldPosition().z - collisionComponent->GetBoundingBox().r.z * 2.0f * GetWorldScale().z * dir), targetAngle, dir);
	p->SetImpulseForce(glm::vec3(0.0f, 0.0f, 200.0f));
	p->SetActingForce(glm::vec3(0.0f, 0.0f, 0.0f));
	p->SetKnockbackForce(glm::vec3(0.0f, 25.0f, 10.0f));
	p->SetStunTime(0.3f);
	p->SetDamage(3);
	p->SetElement(WIND);
	projectiles.push_back(p);
	return projectiles;
	}
	if (lightComboTimer > 0 && lightComboPosition == 1 && playerState != BLOCK && playerState != STUN) {

	if (worldPosition.y > 0.1) {
	physicsComponent->SetVelocity(glm::vec3(0, 5, 0));
	}

	lightComboTimer = 0.5f;
	lightComboPosition++;

	Projectile* p = new Projectile(glm::vec3(GetWorldPosition().x, GetWorldPosition().y, GetWorldPosition().z - collisionComponent->GetBoundingBox().r.z * 2.0f * GetWorldScale().z * dir), targetAngle, dir);
	p->SetImpulseForce(glm::vec3(125.0f, 0.0f, 200.0f));
	p->SetActingForce(glm::vec3(-10.0f, 0.0f, 0.0f));
	p->SetKnockbackForce(glm::vec3(0.0f, 100.0f, 10.0f));
	p->SetStunTime(0.3f);
	p->SetDamage(3);
	p->SetWorldScale(0.5f);
	p->SetElement(WIND);
	projectiles.push_back(p);
	return projectiles;
	}
	if (lightComboTimer > 0 && lightComboPosition == 2 && playerState != BLOCK && playerState != STUN) {

	if (worldPosition.y > 0.1) {
	physicsComponent->SetVelocity(glm::vec3(0, 5, 0));
	}

	lightComboTimer = 0.5f;
	lightComboPosition++;

	Projectile* p = new Projectile(glm::vec3(GetWorldPosition().x, GetWorldPosition().y, GetWorldPosition().z - collisionComponent->GetBoundingBox().r.z * 2.0f * GetWorldScale().z * dir), targetAngle, dir);
	p->SetImpulseForce(glm::vec3(-200.0f, 335.0f, 375.0f));
	p->SetActingForce(glm::vec3(20.0f, -35.0f, 0.0f));
	p->SetKnockbackForce(glm::vec3(0.0f, -100.0f, 0.0f));
	p->SetStunTime(0.3f);
	p->SetDamage(4);
	p->SetWorldScale(0.5f);
	p->SetElement(WIND);
	projectiles.push_back(p);
	dialogue.playSpecifiedFromState(dialogue.RegularProjectile, 0);
	return projectiles;
	}
	*/
	return projectiles;
}
std::vector<Projectile*> DemoUnit::MediumAttack()
{
	std::vector<Projectile*> projectiles;

	
		//dialogue.playSpecifiedFromState(dialogue.RegularProjectile, 0);


	
	return projectiles;
}
std::vector<Projectile*> DemoUnit::HeavyAttack()
{
	std::vector<Projectile*> projectiles;

	

	
	return projectiles;
}
std::vector<Projectile*> DemoUnit::SpecialAttack()
{
	std::vector<Projectile*> projectiles;

	
	return projectiles;
}
void DemoUnit::InheritedUpdate(const float deltaTime)
{
	/*
	if (worldPosition.y < 0.1f) {
	airAttack = false;
	}

	if (playerState == ATTACK)
	{
	physicsComponent->SetVelocity(glm::vec3(0.0f, physicsComponent->GetVelocity().y, 0.0f));
	}

	if (mediumComboPosition == 1) {
	physicsComponent->SetVelocity(glm::vec3(moveSpeed * 1.1f *  deltaTime * 500 * dir, physicsComponent->GetVelocity().y, physicsComponent->GetVelocity().z));
	base->SetLocalRotation(glm::vec3(0.0f, 0.0f, 1.0f), -0.2f);
	}
	if (mediumComboPosition == 2) {
	physicsComponent->SetVelocity(glm::vec3(-moveSpeed * 1.1f * deltaTime * 500 * dir, physicsComponent->GetVelocity().y, physicsComponent->GetVelocity().z));
	base->SetLocalRotation(glm::vec3(0.0f, 0.0f, 1.0f), 0.2f);
	}
	*/
}
void DemoUnit::InheritedHandleEvents(SDL_Event events)
{

}
void DemoUnit::InheritedHandleStates(const Uint8 *state)
{

}