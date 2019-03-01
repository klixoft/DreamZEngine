#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H


#include <glm/glm.hpp>

class LightSource
{
public:
	LightSource(glm::vec3 position_, float ambiet_, float diffuse_, glm::vec3 lightColour_);
	~LightSource();

	glm::vec3 GetPosition() const;
	//glm::vec2 GetLightStrength() const;
	float GetAmbient() const;
	float GetDiffuse() const;
	glm::vec3 GetLightColor() const;


	void SetPosition(glm::vec3 position_);
	void SetAmbient(float ambient_);
	void SetDiffuse(float specular_);
	void SetLightColor(glm::vec3 lightColour_);

private:
	glm::vec3 position;
	glm::vec2 lightStrength;
	glm::vec3 lightColor;
	float ambient;
	float diffuse;
};



#endif // !LIGHTSOURCE_H


