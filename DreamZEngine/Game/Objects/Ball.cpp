#include "Ball.h"

Ball::Ball()
{

	//rand = Randomizer();
	///AI stuff ends

	// Make Ball parts
	base = new ObjectBase("Resources/Objects/golfball.obj");
	base->SetWorldPosition(0.0f, 0.0f, 0.0f);
	base->SetWorldScale(0.05f);
	base->renderComponent->SetColour(0.2f, 0.7f, 0.0f);



	// Initialize collision component
	collisionComponent = new CollisionComponent();
	collisionComponent->CreateCollisionVolume(CollisionComponent::Collision_Type::BOX, base->renderComponent->getVertexList());
	collisionComponent->SetBoxPadding(glm::vec3(0.7f, 1.7f, 0.7f));

	// Initialize physics componenet
	physicsComponent = new PhysicsComponent();
	physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::VERY_ELASTIC);
	physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::PERFECT_SMOOTH);
	physicsComponent->SetMass(50.0f);


}

Ball::~Ball()
{
	// TODO: delete everything
}


void Ball::Update(const float deltaTime)
{


}

void Ball::FixedUpdate(const float deltaTime) {



	// Update collision and physics
	physicsComponent->Update(deltaTime);
	SetWorldPosition(physicsComponent->GetPosition());
	collisionComponent->Update(GetWorldPosition());







	// Update function from child
	InheritedUpdate(deltaTime);
}

void Ball::HandleEvents(SDL_Event events) ///THIS HAS BEEN BANNED IN ACCORDENCE WITH THE NEW CONTROLLER FUNCTIONALITY. USE HandleControllerEvents instead
{
	// Child events
	//InheritedHandleEvents(events); ///we will also need to ban this function, but no one uses it anyways
}

void Ball::HandleStates(const Uint8 *state)
{
	InheritedHandleStates(state);
}





void Ball::Render(Shader* shader, const double _interpolation)
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

void Ball::Bounce(float impulse)
{
	physicsComponent->AddForce(glm::vec3(0.0f, impulse, 0.0f));
}

