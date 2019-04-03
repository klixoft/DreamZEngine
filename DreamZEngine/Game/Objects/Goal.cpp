#include "Goal.h"

Goal::Goal()
{

	//rand = Randomizer();
	///AI stuff ends

	// Make Goal parts
	base = new ObjectBase("Resources/Objects/goal.obj");
	base->SetWorldPosition(0.0f, 0.0f, 0.0f);
	base->SetWorldScale(0.02f, 0.02f, 0.02f);
	
	base->renderComponent->SetColour(0.2f, 0.7f, 0.0f);



	// Initialize collision component
	collisionComponent = new CollisionComponent();
	collisionComponent->CreateCollisionVolume(CollisionComponent::Collision_Type::BOX, base->renderComponent->getVertexList());
	collisionComponent->SetBoxPadding(glm::vec3(2.7f, 4.7f, 2.7f));

	// Initialize physics componenet
	physicsComponent = new PhysicsComponent();
	physicsComponent->SetAcceleration(glm::vec3(0.0f, -25.0f, 0.0f));
	physicsComponent->SetPhysicsType(PhysicsComponent::Physics_Type::DYNAMIC);
	physicsComponent->SetElasticity(PhysicsComponent::Elastic_Type::NON_ELASTIC);
	physicsComponent->SetMaterialType(PhysicsComponent::Material_Type::ROUGH);
	physicsComponent->SetMass(50.0f);


}

Goal::~Goal()
{
	// TODO: delete everything
}


void Goal::Update(const float deltaTime)
{


}

void Goal::FixedUpdate(const float deltaTime) {



	// Update collision and physics
	physicsComponent->Update(deltaTime);
	SetWorldPosition(physicsComponent->GetPosition());
	collisionComponent->Update(GetWorldPosition());







	// Update function from child
	InheritedUpdate(deltaTime);
}

void Goal::HandleEvents(SDL_Event events) ///THIS HAS BEEN BANNED IN ACCORDENCE WITH THE NEW CONTROLLER FUNCTIONALITY. USE HandleControllerEvents instead
{
	// Child events
	//InheritedHandleEvents(events); ///we will also need to ban this function, but no one uses it anyways
}

void Goal::HandleStates(const Uint8 *state)
{
	InheritedHandleStates(state);
}





void Goal::Render(Shader* shader, const double _interpolation)
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

void Goal::Bounce()
{
	physicsComponent->AddForce(glm::vec3(0.0f, 110.0f, 0.0f));
}

