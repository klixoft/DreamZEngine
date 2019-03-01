#include "MaterialsHandler.h"

std::unique_ptr<MaterialsHandler> MaterialsHandler::materialInstance = nullptr;
std::map<std::string, Material> MaterialsHandler::materials = std::map<std::string, Material>();

MaterialsHandler::MaterialsHandler()
{
}


MaterialsHandler::~MaterialsHandler()
{
	if (materials.size() > 0)
	{
		materials.clear();
	}
}

MaterialsHandler* MaterialsHandler::GetInstance()
{
	if (materialInstance.get() == nullptr)
	{
		materialInstance.reset(new MaterialsHandler);
	}
	return materialInstance.get();
}


void MaterialsHandler::AddMaterial(const std::string& name_, Material mat_)
{
	materials.insert(std::pair<std::string, Material>(name_, mat_));

}

const Material MaterialsHandler::GetMaterial(const std::string& matName_)
{
	if (materials.find(matName_) != materials.end())
	{
		return materials[matName_];
	}
	return Material();
}
