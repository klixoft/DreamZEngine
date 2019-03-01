#ifndef BASICLIGHT_H
#define BASICLIGHT_H


#include "../Rendering/3D/Model.h"
#include "LightingManager.h"

class BasicLight
{
public:
	BasicLight(Shader* shaderProgram_, std::string tag_);
	~BasicLight();

	Shader* ourShader = new Shader("Engine/Shaders/camVert.glsl", "Engine/Shaders/camFrag.glsl");

	GLuint CreateBasicLightInstance(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);

	void UpdateInstance(GLuint index_, glm::vec3  position_, float angle_, glm::vec3 rotation, glm::vec3 scale_);
	glm::mat4 GetTransform(GLuint index_) const;
	glm::mat4 GetTransform(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);
	std::string tag;
	void CreateVertexBuffers();
	void Render();
	GLuint loadTexture(char const * path);
	GLuint VBO, VAO, EBO, shaderProgram, texture1, texture2, lightVAO, cubeVAO, diffuseMap, specularMap;
	//GLuint VBO, VAO, EBO, shaderProgram, texture1, texture2, lightVAO, cubeVAO;

	Shader* GetShader() { return ourShader; }
	
private:
	std::vector<glm::mat4> modelInstances;
	glm::vec3 lightPos = glm::vec3(0.2f, 0.0f, 2.0f);
};





#endif // !BASICLIGHT_H

