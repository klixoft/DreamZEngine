#ifndef LIGHTINGMANAGER_H
#define LIGHTINGMANAGER_H

#include <memory>
#include <map>
#include <vector>

#include "../Core/EngineClass.h"


enum LightEnum {
	DIRLIGHT,
	SPOTLIGHT,
	POINTLIGHT
};
struct LightStruct {

	std::string lightTag_;
	glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 position = glm::vec3();
	glm::vec3 ambient = glm::vec3(0.05f, 0.05f, 0.05f);
	glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
	glm::vec3 specular = glm::vec3(0.0f, 0.0f, 0.0f);
	float constant = 1.0f;
	float linear = 0.09f;
	float quadratic = 0.032f;
	glm::vec3 cutOff = glm::vec3(glm::cos(glm::radians(12.5f)));
	glm::vec3 outerCutOff = glm::vec3(glm::cos(glm::radians(15.0f)));

};



class LightingManager
{
public:
	LightingManager(const LightingManager&) = delete;
	LightingManager(LightingManager&&) = delete;
	LightingManager& operator=(const LightingManager&) = delete;
	LightingManager& operator=(LightingManager&&) = delete;


	static LightingManager* GetInstance();


	//void Update(const float deltaTime_);
	void CreateLight(std::string lightName_, LightStruct* lightstruct_);
	void AddLight(std::string lightName_, LightStruct* lights_);
	void UpdateLightPosition(std::string lightName_, glm::vec3 position_);




	std::vector< LightStruct*> GetLights() { return allLights; }
	LightStruct* GetLightValueForUpdating(std::string lightName_) { return lights[lightName_]; };



private:
	LightingManager();
	~LightingManager();

	static std::unique_ptr<LightingManager> lightingManagerInstance;
	friend std::default_delete<LightingManager>;


	std::map<std::string, LightStruct*> lights;
	std::vector< LightStruct*> allLights;

	//static std::map<std::string, LightStruct*> sceneLights;

};



#endif // !LIGHTINGMANAGER_H

