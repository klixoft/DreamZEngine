//#ifndef BOUNDINGBOX_H
//#define BOUNDINGBOX_H
//
//#include <glm/glm.hpp>
//#include <glm/gtx/matrix_decompose.hpp>
//#include <glm/gtx/string_cast.hpp>
//#include "../Graphics/Shader.h"
//#include "../Camera/Camera.h"
//struct BoundingBox {
//
//	glm::vec3 minVert;
//	glm::vec3 maxVert;
//	glm::mat4 transform;
//	GLuint VBO, VAO;
//
//	Shader BoundingBoxShader = Shader("Engine/Shaders/lampVert.glsl", "Engine/Shaders/lampFrag.glsl");
//	inline BoundingBox() {
//		minVert = glm::vec3(0.0f);
//		maxVert = glm::vec3(0.0f);
//		transform = glm::mat4(0.0f);
//	}
//
//	inline void CreateVertexBuffer()
//	{
//		float vertices[] = {
//		minVert.x,minVert.y,minVert.z,
//		maxVert.x,minVert.y,minVert.z,
//		maxVert.x,maxVert.y,minVert.z,
//		minVert.x,maxVert.y,minVert.z,
//		minVert.x,minVert.y,minVert.z,
//		maxVert.x,minVert.y,minVert.z,
//		minVert.x,minVert.y,minVert.z,
//		minVert.x,minVert.y,maxVert.z,
//		minVert.x,maxVert.y,minVert.z,
//		minVert.x,minVert.y,minVert.z,
//		minVert.x,minVert.y,maxVert.z,
//		minVert.x,maxVert.y,maxVert.z,
//		minVert.x,minVert.y,maxVert.z,
//		maxVert.x,minVert.y,maxVert.z,
//		minVert.x,maxVert.y,maxVert.z,
//		minVert.x,minVert.y,maxVert.z,
//		maxVert.x,minVert.y,maxVert.z,
//		maxVert.x,maxVert.y,maxVert.z,
//		maxVert.x,minVert.y,minVert.z,
//		maxVert.x,maxVert.y,minVert.z,
//		maxVert.x,maxVert.y,maxVert.z,
//		maxVert.x,minVert.y,minVert.z,
//		maxVert.x,maxVert.y,minVert.z,
//		minVert.x,maxVert.y,minVert.z,
//		minVert.x,minVert.y,minVert.z,
//		maxVert.x,minVert.y,minVert.z,
//		minVert.x,minVert.y,maxVert.z,
//		minVert.x,minVert.y,minVert.z,
//		maxVert.x,minVert.y,minVert.z,
//		maxVert.x,minVert.y,maxVert.z,
//		minVert.x,maxVert.y,minVert.z,
//		maxVert.x,maxVert.y,minVert.z,
//		maxVert.x,maxVert.y,maxVert.z,
//		minVert.x,maxVert.y,minVert.z,
//		maxVert.x,maxVert.y,minVert.z,
//		minVert.x,maxVert.y,maxVert.z
//		};
//		// first, configure the cube's VAO (and VBO)
//
//
//		glGenBuffers(1, &VBO);
//
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//		glGenVertexArrays(1, &VAO);
//		glBindVertexArray(VAO);
//
//		// we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//		glEnableVertexAttribArray(0);
//
//
//	}
//	inline BoundingBox(glm::vec3 minVert_, glm::vec3 maxVert_, glm::mat4 transform_) {
//		minVert = minVert_;
//		maxVert = maxVert_;
//		transform = transform_;
//	}
//
//	inline bool Intersects(BoundingBox* box_)
//	{
//		glm::vec3 minCorner = GetTrandformedPoint(minVert, transform);
//		glm::vec3 maxCorner = GetTrandformedPoint(maxVert, transform);
//		glm::vec3 other_minCorner= GetTrandformedPoint(box_->minVert, box_->transform);
//		glm::vec3 other_maxCorner= GetTrandformedPoint(box_->maxVert, box_->transform);
//
//		return true;
//	}
//
//	inline void Render()
//	{
//		glm::mat4 projection = glm::perspective(glm::radians(90.0f), (float)800 / (float)600, 2.0f, 50.0f);
//		glm::mat4 view = Camera::GetInstance()->GetViewMatrix();
//
//		BoundingBoxShader.setMat4("projection", projection);
//		BoundingBoxShader.setMat4("view", view);
//		glBindVertexArray(VAO);
//
//		BoundingBoxShader.setMat4("model", transform);
//
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//	}
//private:
//	inline glm::vec3 GetTrandformedPoint(glm::vec3 point_, glm::mat4 transform_)
//	{
//		glm::vec3 scale;
//		glm::quat rotation;
//		glm::vec3 translation;
//		glm::vec3 skew;
//		glm::vec4 perspective;
//		glm::decompose(transform_, scale, rotation, translation, skew, perspective);
//		return point_ + translation;
//	}
//
//	
//
//
//};
//
//#endif
