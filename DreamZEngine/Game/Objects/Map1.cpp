#include "Map1.h"



Map1::Map1()
{
	
	// Make Map1 parts
	base = new Arena("Resources/Objects/area/arena.obj");
	base->SetWorldPosition(0.0f, 0.0f, 0.0f);
	base->SetWorldScale(1.0f);
	base->renderComponent->SetColour(0.2f, 0.7f, 0.0f);



	// Initialize collision component
	collisionComponent = new CollisionComponent();
	collisionComponent->CreateCollisionVolume(CollisionComponent::Collision_Type::BOX, base->renderComponent->getVertexList());
	collisionComponent->SetBoxPadding(glm::vec3(21.0f, 1.2f, 21.0f));

	// Initialize physics componenet
	physicsComponent = new PhysicsComponent();
	physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::VERY_ELASTIC);
	physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	

	
}

Map1::~Map1()
{
	// TODO: delete everything
}



void Map1::Update(const float deltaTime)
{



}

void Map1::FixedUpdate(const float deltaTime) {

	

	// Update collision and physics
	physicsComponent->Update(deltaTime);
	SetWorldPosition(physicsComponent->GetPosition());
	collisionComponent->Update(GetWorldPosition());


}

void Map1::Render(Shader* shader, const double _interpolation)
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