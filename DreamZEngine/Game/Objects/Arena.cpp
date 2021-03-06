#include "Arena.h"



Arena::Arena()
{
	renderComponent = new RenderComponent();
	renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
}

Arena::Arena(std::string path)
{
	model = new Model(path, true);
	//model->SetWorldRotation(glm::vec3(0.0f, 1.0f, 0.0f), 1.5708f);

	renderComponent = new RenderComponent();
	renderComponent->SetRenderType(RenderComponent::Render_Type::CUBE);
	renderComponent->CanRender(false);
}

Arena::~Arena()
{
}

void Arena::Update(const float deltaTime)
{

}

void Arena::Render(Shader* shader, const double _interpolation)
{
	if (renderComponent != NULL) {
		renderComponent->Render(shader);
	}

	if (model != NULL) {
		model->Render(shader, _interpolation);
	}
}