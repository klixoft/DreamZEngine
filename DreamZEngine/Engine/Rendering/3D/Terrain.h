//#ifndef TERRAIN_H
//
//#define TERRAIN_H
//
//
//
//#include "Model.h"
//#include "../../FX/LightingManager.h"
//
//class Terrain
//{
//public:
//	Terrain(Shader* shaderProgram_);
//	~Terrain();
//
//	Shader* ourShader = new Shader("Engine/Shaders/camVert.glsl", "Engine/Shaders/camFrag.glsl");
//
//
//
//	void UpdateInstance(GLuint index_, glm::vec3  position_, float angle_, glm::vec3 rotation, glm::vec3 scale_);
//	glm::mat4 GetTransform(GLuint index_) const;
//	glm::mat4 GetTransform(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);
//	std::string tag;
//	void CreateVertexBuffers();
//	void Render();
//	GLuint loadTexture(char const * path);
//	GLuint VBO, VAO, EBO, shaderProgram, texture1, texture2, lightVAO, cubeVAO, diffuseMap, specularMap, planeVAO, planeVBO, floorTexture;
//	//GLuint VBO, VAO, EBO, shaderProgram, texture1, texture2, lightVAO, cubeVAO;
//
//	Shader* GetShader() { return ourShader; }
//	glm::vec3 cubePositions[10] = {
//	   glm::vec3(0.0f,  0.0f,  0.0f),
//	   glm::vec3(2.0f,  5.0f, -15.0f),
//	   glm::vec3(-1.5f, -2.2f, -2.5f),
//	   glm::vec3(-3.8f, -2.0f, -12.3f),
//	   glm::vec3(2.4f, -0.4f, -3.5f),
//	   glm::vec3(-1.7f,  3.0f, -7.5f),
//	   glm::vec3(1.3f, -2.0f, -2.5f),
//	   glm::vec3(1.5f,  2.0f, -2.5f),
//	   glm::vec3(1.5f,  0.2f, -1.5f),
//	   glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	glm::vec3 pointLightColors[4] = {
//	glm::vec3(1.0f, 0.6f, 0.0f),
//	glm::vec3(1.0f, 0.0f, 0.0f),
//	glm::vec3(1.0f, 1.0, 0.0),
//	glm::vec3(0.2f, 0.2f, 1.0f)
//	};
//
//	glm::vec3 pointLightPositions[4] = {
//	   glm::vec3(0.7f,  0.2f,  2.0f),
//	   glm::vec3(2.3f, -3.3f, -4.0f),
//	   glm::vec3(-4.0f,  2.0f, -12.0f),
//	   glm::vec3(0.0f,  0.0f, -3.0f)
//	};
//	Shader lampShader = Shader("Engine/Shaders/lampVert.glsl", "Engine/Shaders/lampFrag.glsl");
//	Shader lightingShader = Shader("Engine/Shaders/colorVert.glsl", "Engine/Shaders/colorFrag.glsl");
//private:
//	std::vector<glm::mat4> modelInstances;
//	glm::vec3 lightPos = glm::vec3(0.2f, 0.0f, 2.0f);
//};
//
//
//
//
//
//#endif // !TERRAIN_H
//
//
