#pragma once
#ifndef ARENA_H
#define ARENA_H

#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Core/RenderComponent.h"
#include "../../Engine/Rendering/3D/Model.h"





class Arena : public GameObject
{
public:
	Arena();
	Arena(std::string path);
	~Arena();

	void Update(const float deltaTime);
	void Render(Shader* shader, const double _interpolation);

	RenderComponent* renderComponent;
	Model* model;
};


#endif

