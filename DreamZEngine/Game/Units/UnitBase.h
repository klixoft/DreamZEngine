#pragma once
#ifndef UNITBASE_H
#define UNITBASE_H

#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Core/RenderComponent.h"
#include "../../Engine/Rendering/3D/Model.h"





	class UnitBase : public GameObject
	{
	public:
		UnitBase();
		UnitBase(std::string path);
		~UnitBase();

		void Update(const float deltaTime);
		void Render(Shader* shader, const double _interpolation);

		RenderComponent* renderComponent;
		Model* model;
	};


#endif

