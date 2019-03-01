//#include "Terrain.h"
//
//
//#include <sstream>
//
//
//Terrain::Terrain(Shader* shaderProgram_)
//{
//	ourShader = shaderProgram_;
//	//tag = tag_;
//	CreateVertexBuffers();
//}
//
//
//Terrain::~Terrain()
//{
//}
//
//
//
//void Terrain::CreateVertexBuffers()
//{
//	float planeVertices[] = {
//		// positions            // normals         // texcoords
//		 10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
//		-10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
//		-10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
//
//		 10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
//		-10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
//		 10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
//	};
//	// plane VAO
//
//	glGenVertexArrays(1, &planeVAO);
//	glGenBuffers(1, &planeVBO);
//	glBindVertexArray(planeVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glBindVertexArray(0);
//
//	// load textures
//	// -------------
//	floorTexture = loadTexture("Resources/Textures/wood.png");
//
//	// shader configuration
//	// --------------------
//	ourShader->use();
//	ourShader->setInt("texture1", 0);
//
//	ourShader->setInt("lightsize", LightingManager::GetInstance()->GetLights().size());
//}
//
//void Terrain::Render()
//{
//
//	// draw objects
//	ourShader->use();
//	glm::mat4 projection = glm::perspective(glm::radians(Camera::GetInstance()->Zoom), (float)1280 / (float)720, 0.1f, 100.0f);
//	glm::mat4 view = Camera::GetInstance()->GetViewMatrix();
//	ourShader->setMat4("projection", projection);
//	ourShader->setMat4("view", view);
//	// set light uniforms
//	ourShader->setVec3("viewPos", Camera::GetInstance()->Position);
//	glBindVertexArray(planeVAO);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, floorTexture);
//
//
//	if (LightingManager::GetInstance()->GetLights().size() != 0)
//	{
//		for (int i = 0; i < LightingManager::GetInstance()->GetLights().size(); i++)
//		{
//			const string position = "lights[" + std::to_string(i) + "].position";
//			const string ambient = "pointLights[" + std::to_string(i) + "].ambient";
//			const string diffuse = "pointLights[" + std::to_string(i) + "].diffuse";
//			const string specular = "pointLights[" + std::to_string(i) + "].specular";
//
//			ourShader->setVec3(position, LightingManager::GetInstance()->GetLights()[i]->position);
//			ourShader->setVec3(ambient, LightingManager::GetInstance()->GetLights()[i]->ambient);
//			ourShader->setVec3(diffuse, LightingManager::GetInstance()->GetLights()[i]->diffuse);
//			ourShader->setVec3(specular, LightingManager::GetInstance()->GetLights()[i]->specular);
//
//			glDrawArrays(GL_TRIANGLES, 0, 6);
//		}
//	}
//	else {
//		ourShader->setInt("lightsizes", 0);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//	}
//
//
//	//std::cout << (blinn ? "Blinn-Phong" : "Phong") << std::endl;
//
//}
//
//GLuint Terrain::loadTexture(char const * path)
//{
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//
//	int width, height, nrComponents;
//	unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
//	if (data)
//	{
//		GLenum format;
//		if (nrComponents == 1)
//			format = GL_RED;
//		else if (nrComponents == 3)
//			format = GL_RGB;
//		else if (nrComponents == 4)
//			format = GL_RGBA;
//
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		stbi_image_free(data);
//	}
//	else
//	{
//		std::cout << "Texture failed to load at path: " << path << std::endl;
//		stbi_image_free(data);
//	}
//
//	return textureID;
//}