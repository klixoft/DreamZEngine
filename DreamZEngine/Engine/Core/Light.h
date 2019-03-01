#pragma once
#ifndef LIGHT_H
#define LIGHT_H

#include "../Rendering/3D/GameObject.h"
#include "LightComponent.h"
#include "../Core/RenderComponent.h"



	class Light : public GameObject
	{
	public:
		Light();
		Light(LightComponent::Light_Type lt);
		~Light();

		void Render(Shader* shader, const double _interpolation);

		LightComponent* lightComponent;
		RenderComponent* renderComponent;
	};



#endif
