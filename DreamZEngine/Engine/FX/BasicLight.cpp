//#include "BasicLight.h"
//#include <sstream>
//
//
//BasicLight::BasicLight(Shader* shaderProgram_, std::string tag_)
//{
//	ourShader = shaderProgram_;
//	tag = tag_;
//	CreateVertexBuffers();
//}
//
//
//BasicLight::~BasicLight()
//{
//}
//
//GLuint BasicLight::CreateBasicLightInstance(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_)
//{
//	modelInstances.push_back(GetTransform(position_, angle_, rotation_, scale_));
//	return modelInstances.size() - 1;
//}
//
//void BasicLight::UpdateInstance(GLuint index_, glm::vec3  position_, float angle_, glm::vec3 rotation, glm::vec3 scale_)
//{
//	modelInstances[index_] = GetTransform(position_, angle_, rotation, scale_);
//}
//
//glm::mat4 BasicLight::GetTransform(GLuint index_) const
//{
//	return modelInstances[index_];
//}
//
//
//
//glm::mat4 BasicLight::GetTransform(glm::vec3  position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_)
//{
//	glm::mat4 model;
//	model = glm::translate(model, position_);
//	model = glm::rotate(model, angle_, rotation_);
//	model = glm::scale(model, scale_);
//
//	return model;
//}
//
//
//void BasicLight::CreateVertexBuffers()
//{
//	float vertices[] = {
//	-0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f,  0.5f, -0.5f,
//	 0.5f,  0.5f, -0.5f,
//	-0.5f,  0.5f, -0.5f,
//	-0.5f, -0.5f, -0.5f,
//
//	-0.5f, -0.5f,  0.5f,
//	 0.5f, -0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f,  0.5f,
//	-0.5f, -0.5f,  0.5f,
//
//	-0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f, -0.5f,
//	-0.5f, -0.5f, -0.5f,
//	-0.5f, -0.5f, -0.5f,
//	-0.5f, -0.5f,  0.5f,
//	-0.5f,  0.5f,  0.5f,
//
//	 0.5f,  0.5f,  0.5f,
//	 0.5f,  0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//
//	-0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f, -0.5f,
//	 0.5f, -0.5f,  0.5f,
//	 0.5f, -0.5f,  0.5f,
//	-0.5f, -0.5f,  0.5f,
//	-0.5f, -0.5f, -0.5f,
//
//	-0.5f,  0.5f, -0.5f,
//	 0.5f,  0.5f, -0.5f,
//	 0.5f,  0.5f,  0.5f,
//	 0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f,  0.5f,
//	-0.5f,  0.5f, -0.5f,
//	};
//	// first, configure the cube's VAO (and VBO)
//	;
//
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	glGenVertexArrays(1, &lightVAO);
//	glBindVertexArray(lightVAO);
//
//	// we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	// second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
//
//
//
//}
//
//void BasicLight::Render()
//{
//
//
//
//
//
//
//	// view/projection transformations
//	glm::mat4 projection = glm::perspective(glm::radians(Camera::GetInstance()->Zoom), (float)1280 / (float)720, 0.1f, 100.0f);
//	glm::mat4 view = Camera::GetInstance()->GetViewMatrix();
//
//
//	// world transformation
//	glm::mat4 model = glm::mat4(1.0f);
//
//	// also draw the lamp object
//
//	ourShader->setMat4("projection", projection);
//	ourShader->setMat4("view", view);
//
//
//	glBindVertexArray(lightVAO);
//
//
//
//
//
//
//	for (int i = 0; i < LightingManager::GetInstance()->GetLights().size(); i++)
//	{
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, LightingManager::GetInstance()->GetLights()[i]->position);
//		model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
//		ourShader->setMat4("model", model);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//	}
//}
//
//GLuint BasicLight::loadTexture(char const * path)
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