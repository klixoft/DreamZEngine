#pragma once
#ifndef ObjectBase_H
#define ObjectBase_H

#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Core/RenderComponent.h"
#include "../../Engine/Rendering/3D/Model.h"





	class ObjectBase : public GameObject
	{
	public:
		ObjectBase();
		ObjectBase(std::string path);
		~ObjectBase();

		void Update(const float deltaTime);
		void Render(Shader* shader, const double _interpolation);

		RenderComponent* renderComponent;
		Model* model;
	};


#endif

