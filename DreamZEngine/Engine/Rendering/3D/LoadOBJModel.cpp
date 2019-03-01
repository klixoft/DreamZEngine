//
//
//#include "LoadOBJModel.h"
//#include <algorithm>
//
//
//LoadOBJModel::LoadOBJModel():currentMaterial(Material())
//{
//}
//
//
//LoadOBJModel::~LoadOBJModel()
//{
//	vertices.clear();
//	vertices.shrink_to_fit();
//	normals.clear();
//	normals.shrink_to_fit();
//	textureCoords.clear();
//	textureCoords.shrink_to_fit();
//	indices.clear();
//	indices.shrink_to_fit();
//	normalIndices.clear();
//	normalIndices.shrink_to_fit();
//	textureIndices.clear();
//	textureIndices.shrink_to_fit();
//	meshVertices.clear();
//	meshVertices.shrink_to_fit();
//	meshes.clear();
//	meshes.shrink_to_fit();
//}
//
//void LoadOBJModel::LoadModel(const std::string& fileName_)
//{
//	std::string fullPath = "Resources/Models/";
//	fullPath.append(fileName_);
//	//std::cout << fullPath;
//	std::ifstream in(fullPath.c_str(), std::ios::in);
//	if (!in)
//	{
//		Debug::Error("Cannot open OBJ file " + fileName_ , __FILE__, __LINE__);
//		return;
//	}
//	else {
//		std::string line;
//		boundingBox.minVert = glm::vec3(100000);
//		boundingBox.maxVert = glm::vec3(-10000);
//		while (std::getline(in, line))
//		{
//			//VERTEXDATA
//			if (line.substr(0, 2) == "v ")
//			{
//				
//				std::istringstream v(line.substr(2));
//				double x, y, z;
//				v >> x >> y >> z;
//				vertices.push_back(glm::vec3(x, y, z));
//			
//				
//
//					if (boundingBox.minVert.x > x)
//					{
//						boundingBox.minVert.x = x;				
//					}
//
//					if (boundingBox.minVert.y > y)
//					{
//						boundingBox.minVert.y = y;
//					}
//					if (boundingBox.minVert.z > z)
//					{
//						
//						boundingBox.minVert.z = z;
//					}
//
//					if (boundingBox.maxVert.x < x)
//					{
//						boundingBox.maxVert.x = x;
//					
//					}
//					if (boundingBox.maxVert.y < y)
//					{
//						
//						boundingBox.maxVert.y = y;
//					}
//					if (boundingBox.maxVert.z < z)
//					{
//						boundingBox.maxVert.z = z;
//						
//					}
//
//					
//				
//
//			}
//
//			//NORMALDATA
//			else if (line.substr(0, 3) == "vn ")
//			{
//				
//				std::istringstream v(line.substr(2));
//				double n1, n2, n3;
//				v >> n1 >> n2 >> n3;
//				normals.push_back(glm::vec3(n1, n2, n3));
//
//			}
//			//TEXTURE COORDINATE  DATA
//			else if (line.substr(0, 3) == "vt ")
//			{
//				
//				std::istringstream v(line.substr(2));
//				double t1, t2, t3;
//				v >> t1 >> t2 >> t3;
//				textureCoords.push_back(glm::vec2(t1, t2));
//
//			}
//			//FACEDATA
//			else if (line.substr(0, 2) == "f ")
//			{
//				
//				std::istringstream v(line.substr(2));
//				//std::string vertex1, vertex2, vertex3;
//				std::string t1, t2, t3;
//				v >> t1 >> t2 >> t3;
//
//				std::string delimiter = "/";
//				{
//					int i, t, n;
//					char c;
//					std::istringstream v1(t1);
//					v1 >> i >> c >> t >> c >> n;
//					i--;
//					t--;
//					n--;
//					indices.push_back(i);
//					textureIndices.push_back(t);
//					normalIndices.push_back(n);
//					
//				}
//				{
//					int i, t, n;
//					char c;
//					std::istringstream v2(t2);
//					v2 >> i >> c >> t >> c >> n;
//					i--;
//					t--;
//					n--;
//					indices.push_back(i);
//					textureIndices.push_back(t);
//					normalIndices.push_back(n);
//					//std::string token = t2.substr(0, t2.find(delimiter)); // token is "scott"
//					//t2.erase(0, t2.find(delimiter) + delimiter.length());
//					//int index = stoi(token)-1;
//					////	std::cout << index;
//					//indices.push_back(index);
//					//std::string token2 = t2.substr(0, t2.find(delimiter)); // token is "scott"
//					//int texindex = stoi(token2)-1;
//					////	std::cout << texindex;
//					//textureIndices.push_back(texindex);
//					//t2.erase(0, t2.find(delimiter) + delimiter.length());
//					//std::string token3 = t2.substr(0, t2.find(delimiter)); // token is "scott"
//					//int normIndex = stoi(token3)-1;
//					////	std::cout << normIndex << std::endl;
//					//normalIndices.push_back(normIndex);
//				}
//				{
//					int i, t, n;
//					char c;
//					std::istringstream v3(t3);
//					v3 >> i >> c >> t >> c >> n;
//					i--;
//					t--;
//					n--;
//					indices.push_back(i);
//					textureIndices.push_back(t);
//					normalIndices.push_back(n);
//				//	std::string token = t3.substr(0, t3.find(delimiter)); // token is "scott"
//				//	t3.erase(0, t3.find(delimiter) + delimiter.length());
//				//	int index = stoi(token)-1;
//				//	//	std::cout << index;
//				//	indices.push_back(index);
//				//	std::string token2 = t3.substr(0, t3.find(delimiter)); // token is "scott"
//				//	int texindex = stoi(token2)-1;
//				//	//	std::cout << texindex;
//				//	textureIndices.push_back(texindex);
//				//	t3.erase(0, t3.find(delimiter) + delimiter.length());
//				//	std::string token3 = t3.substr(0, t3.find(delimiter)); // token is "scott"
//				//	int normIndex = stoi(token3)-1;
//				////	std::cout << normIndex << std::endl;
//				//	normalIndices.push_back(normIndex);
//				}
//				
//
//				//meshVertices.push_back()
//
//			}
//			//NEWMATERIAL
//			else if (line.substr(0, 7) == "usemtl ")
//			{
//				
//				if (indices.size() > 0)
//				{
//					PostProcessing();
//				}
//				LoadMaterial(line.substr(7));
//			}
//
//		}
//		PostProcessing();
//
//	}
//
//	
//	
//}
////bounding box set min and max 
////somewhere in where u load vertex
//BoundingBox LoadOBJModel::GetBoundingBox()
//{
//	return boundingBox;
//}
//void LoadOBJModel::LoadModel(const std::string& fileName_, const std::string& matName_)
//{
//	LoadMaterialLibrary(matName_);
//	LoadModel(fileName_);
//}
//void LoadOBJModel::PostProcessing()
//{
//	for (int i = 0; i < indices.size(); i++)
//	{
//		Vertex vert;
//		vert.position = vertices[indices[i]];
//		vert.normal = normals[normalIndices[i]];
//		vert.texCoords = textureCoords[textureIndices[i]];
//		meshVertices.push_back(vert);
//	}
//
//	SubMesh mesh;
//	mesh.vertexList = meshVertices;
//	mesh.meshIndices = indices;
//	mesh.material = currentMaterial;
//	meshes.push_back(mesh);
//	indices.clear();
//	indices.shrink_to_fit();
//	normalIndices.clear();
//	normalIndices.shrink_to_fit();
//	textureIndices.clear();
//	textureIndices.shrink_to_fit();
//	meshVertices.clear();
//	meshVertices.shrink_to_fit();
//	currentMaterial = Material();
//}
//
//void LoadOBJModel::LoadMaterial(const std::string& fileName_)
//{
//	currentMaterial = MaterialsHandler::GetInstance()->GetMaterial(fileName_);
//	
//}
//
//void LoadOBJModel::LoadMaterialLibrary(const std::string& matName_)
//{
//	MaterialLoader::LoadMaterial(matName_);
//}
//
//std::vector<Vertex> LoadOBJModel::GetVerts()
//{
//	return meshVertices;
//}
//
//std::vector<GLuint> LoadOBJModel::GetIndices()
//{
//	return indices;
//}
//
//std::vector<SubMesh> LoadOBJModel::GetMeshes()
//{
//	return meshes;
//}
