#include "ObjectBase.h"



ObjectBase::ObjectBase()
{
	renderComponent = new RenderComponent();
	renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
}

ObjectBase::ObjectBase(std::string path) 
{
	model = new Model(path, true);
	//model->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), 1.5708f);

	renderComponent = new RenderComponent();
	renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
	renderComponent->CanRender(false);
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Update(const float deltaTime)
{
}

void ObjectBase::Render(Shader* shader, const double _interpolation)
{
	if (renderComponent != NULL) {
		renderComponent->Render(shader);
	}

	if (model != NULL) {
		model->Render(shader, _interpolation);
	}
}