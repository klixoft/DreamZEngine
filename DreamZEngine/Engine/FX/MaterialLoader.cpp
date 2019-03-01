//#include "MaterialLoader.h"
//
//
//
//void MaterialLoader::LoadMaterial(std::string file_)
//{
//	std::string fullPath = "Resources/Materials/";
//	fullPath.append(file_);
//	std::ifstream in(fullPath.c_str(), std::ios::in);
//	if (!in)
//	{
//		Debug::Error("Cannot Open MTL file: " + file_, __FILE__, __LINE__);
//		return;
//	}
//	Material m = Material();
//	std::string matName = "";
//	std::string line;
//	while (std::getline(in, line))
//	{
//		if (line.substr(0, 7) == "newmtl ")
//		{
//			if (m.diffuseMap != 0)
//			{
//				MaterialsHandler::GetInstance()->AddMaterial(matName, m);
//				m = Material();
//			}
//			matName = line.substr(7);
//			m.diffuseMap = LoadTexture(matName);
//		}
//
//		//NS = shininess
//		else if (line.substr(0, 4) == "\tNs ")
//		{
//			
//			std::istringstream v(line.substr(4));
//			double n1;
//			v >> n1;
//			m.shininess = n1;
//			
//
//		}
//
//		//d = transparence
//		else if (line.substr(0, 3) == "\td ")
//		{
//
//			std::istringstream v(line.substr(4));
//			double n1;
//			v >> n1;
//			m.transparency = n1;
//
//
//		}
//		//KA=ambient
//		else if (line.substr(0, 4) == "\tKa ")
//		{
//
//			std::istringstream v(line.substr(4));
//			double n1,n2,n3;
//			v >> n1 >>n2>>n3;
//			m.ambient.x = n1;
//			m.ambient.y = n2;
//			m.ambient.z = n3;
//
//
//		}
//
//		//Kd = diffuse
//		else if (line.substr(0, 4) == "\tKd ")
//		{
//
//			std::istringstream v(line.substr(4));
//			double n1, n2, n3;
//			v >> n1 >> n2 >> n3;
//			m.diffuse.x = n1;
//			m.diffuse.y = n2;
//			m.diffuse.z = n3;
//
//
//		}
//		//Ks = specular
//		else if (line.substr(0, 4) == "\tKs ")
//		{
//
//			std::istringstream v(line.substr(4));
//			double n1, n2, n3;
//			v >> n1 >> n2 >> n3;
//			m.specular.x = n1;
//			m.specular.y = n2;
//			m.specular.z = n3;
//
//
//		}
//	}
//	if(m.diffuseMap!=0)
//	{
//		MaterialsHandler::GetInstance()->AddMaterial(matName, m);
//	}
//	
//}
//
//
// GLuint MaterialLoader::LoadTexture(std::string fileName_)
// {
//	 GLuint currentTexture = TextureHandler::GetInstance()->GetTexture(fileName_);
//	 if (currentTexture == 0)
//	 {
//		 TextureHandler::GetInstance()->CreateTexture(fileName_, "Resources/Textures/" + fileName_ + ".jpg");
//		 currentTexture = TextureHandler::GetInstance()->GetTexture(fileName_);
//	 }
//
//	 return currentTexture;
// }