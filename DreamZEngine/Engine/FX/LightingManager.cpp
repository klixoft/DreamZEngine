#include "LightingManager.h"

std::unique_ptr<LightingManager> LightingManager::lightingManagerInstance = nullptr;


LightingManager::LightingManager()
{
}

LightingManager::~LightingManager()
{
}

LightingManager*  LightingManager::GetInstance()
{
	if (lightingManagerInstance.get() == nullptr)
	{
		lightingManagerInstance.reset(new LightingManager);
	}
	return lightingManagerInstance.get();
}

void LightingManager::CreateLight(std::string lightName_, LightStruct* lightstruct_)
{
	//allLights[0].find("sde")->second
	if (lights.find(lightName_) == lights.end())
	{
		lights.insert(std::pair < std::string, LightStruct*>(lightName_, lightstruct_));
		printf(" notfound\n");
		allLights.push_back(lightstruct_);
		//lights.clear();
	}
	else
	{
		printf("found\n");
		lights[lightName_] = lightstruct_;
		for (auto m : allLights)
		{

			if (m->lightTag_ == lightName_)
			{
				m = lightstruct_;
			}
		}
	}

}


void LightingManager::UpdateLightPosition(std::string lightName_, glm::vec3 position_)
{
	//lights[lightName_]->position = position_;
	for (auto m : allLights)
	{

		if (m->lightTag_ == lightName_)
		{
			m->position = position_;
		}
	}

}

