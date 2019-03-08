#pragma once
#ifndef PROJECTILERENDERER_H
#define PROJECTILERENDERER_H

#include "../../Engine/Core/RenderComponent.h"
#include "../../Engine/Core/GameObject.h"
#include "../../Engine/Rendering\3D\Projectile.h"
#include "../../Engine/Rendering\3D\Model.h"
#include "../../Engine/Core/EngineClass.h"




	// This class renders all projectiles in the scene
	class ProjectileRenderer : public GameObject {

	public:

		// Constructors 
		ProjectileRenderer();
		~ProjectileRenderer();

		void Update(const float deltaTime);
		void Render(Shader* shader, const double _interpolation);

		RenderComponent* GetCubeMesh() { return cubeMesh; };

		void SetProjectileList(std::vector<Projectile*> projectileList) { projectiles = projectileList; };

	private:

		// The mesh to be used for rendering 
		RenderComponent* cubeMesh;
		Model* normFire; Model* fireMeteor;
		Model* normEarth; Model* earthStalagmites; Model* earthUlt;
		Model* normIce; Model* iceWall; Model* iceRamp; Model* iceUlt;
		Model* normElec; Model* elecDisc;
		Model* normWind; Model* windDisc; Model* windWall;

		// List of projectiles in the scene
		std::vector<Projectile*> projectiles;
		// Projectiles shader
		Shader* projectileShader;

	};


#endif 
