#ifndef MATERIALSHANDLER_H
#define MATERIALSHANDLER_H

#include <glew.h>
#include <glm/glm.hpp>
#include <map>
#include <memory>

struct Material 
{
	inline Material():diffuseMap(0),shininess(0.0f),transparency(0.0f), ambient(glm::vec3(1.0f)), diffuse(glm::vec3(1.0f)), specular(glm::vec3())
	{

	}

	GLuint diffuseMap;

	float shininess; //Ns
	float transparency; //d

	glm::vec3 ambient;  //Ka
	glm::vec3 diffuse;  //Kd
	glm::vec3 specular; //Ks

};

class MaterialsHandler
{
public:

	MaterialsHandler(const MaterialsHandler&) = delete;
	MaterialsHandler(MaterialsHandler&&) = delete;
	MaterialsHandler& operator=(const MaterialsHandler&) = delete;
	MaterialsHandler& operator=(MaterialsHandler&&) = delete;


	static MaterialsHandler* GetInstance();

	void AddMaterial(const std::string& name_, Material mat_);
	const Material GetMaterial(const std::string& matName_);

private:

	static std::unique_ptr<MaterialsHandler> materialInstance;
	friend std::default_delete<MaterialsHandler>;

	static std::map<std::string, Material> materials;
	MaterialsHandler();
	~MaterialsHandler();
};


#endif // !MATERIALSHANDLER_H

