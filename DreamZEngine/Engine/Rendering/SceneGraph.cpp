//#include "SceneGraph.h"
//
//
//std::unique_ptr<SceneGraph> SceneGraph::sceneGraphInstance = nullptr;
//
//std::map<Shader*, std::vector<BasicLight*>> SceneGraph::sceneLights = std::map<Shader*, std::vector<BasicLight*>>();
//std::map<Shader*, std::vector<Cube*>> SceneGraph::sceneColliders = std::map<Shader*, std::vector<Cube*>>();
//std::map<Shader*, std::vector<Model*>> SceneGraph::sceneModels = std::map<Shader*, std::vector<Model*>>();
//std::map<std::string, GameObject*> SceneGraph::sceneGameObjects = std::map<std::string, GameObject*>();
//std::map<CAMTYPE, Camera*> SceneGraph::sceneCameras = std::map<CAMTYPE, Camera*>();
//
//SceneGraph::SceneGraph()
//{
//}
//
//
//SceneGraph::~SceneGraph()
//{
//	if (sceneGameObjects.size() > 0)
//	{
//		for (auto go : sceneGameObjects)
//		{
//			delete go.second;
//			go.second = nullptr;
//		}
//		sceneGameObjects.clear();
//	}
//
//	if (sceneModels.size() > 0)
//	{
//		for (auto entry : sceneModels)
//		{
//			if (entry.second.size() > 0)
//			{
//				for (auto m : entry.second)
//				{
//					delete m;
//					m = nullptr;
//				}
//				entry.second.clear();
//				entry.second.shrink_to_fit();
//			}
//		}
//		sceneModels.clear();
//	}
//}
//
//SceneGraph*  SceneGraph::GetInstance()
//{
//	if (sceneGraphInstance.get() == nullptr)
//	{
//		sceneGraphInstance.reset(new SceneGraph);
//	}
//	return sceneGraphInstance.get();
//}
//
//
//void SceneGraph::AddModel(Model* model_)
//{
//	if (sceneModels.find(model_->GetShader()) == sceneModels.end())
//	{
//		sceneModels.insert(std::pair < Shader*, std::vector<Model*>>(model_->GetShader(), std::vector<Model*>{model_}));
//	}
//	else
//	{
//		sceneModels[model_->GetShader()].push_back(model_);
//	}
//}
//
//
//void SceneGraph::AddLight(BasicLight* light_, std::string name_, LightStruct* lightstruct_)
//{
//
//
//	if (sceneLights.find(light_->GetShader()) == sceneLights.end())
//	{
//		lightstruct_->lightTag_ = name_;
//		sceneLights.insert(std::pair < Shader*, std::vector<BasicLight*>>(light_->GetShader(), std::vector<BasicLight*>{light_}));
//		LightingManager::GetInstance()->CreateLight(name_, lightstruct_);
//	}
//	else
//	{
//		lightstruct_->lightTag_ = name_;
//		sceneLights[light_->GetShader()].push_back(light_);
//		LightingManager::GetInstance()->CreateLight(name_, lightstruct_);
//	}
//
//}
//void SceneGraph::AddCollider(Cube* cube_)
//{
//
//
//	if (sceneColliders.find(cube_->GetShader()) == sceneColliders.end())
//	{
//		sceneColliders.insert(std::pair < Shader*, std::vector<Cube*>>(cube_->GetShader(), std::vector<Cube*>{cube_}));
//	}
//	else
//	{
//		sceneColliders[cube_->GetShader()].push_back(cube_);
//	}
//
//}
//
//void SceneGraph::AddSkybox(SkyBox * skybox_)
//{
//	skybox = skybox_;
//}
//void SceneGraph::AddTerain(Terrain * terrain_)
//{
//	terrain = terrain_;
//}
//
//
//
//void SceneGraph::AddGameObject(GameObject* go_, std::string name_)
//{
//	if (name_ == "")
//	{
//		std::string newName = "GameObject" + (sceneGameObjects.size() + 1);
//		go_->SetTag(newName);
//		sceneGameObjects[newName] = go_;
//
//	}
//	else if (sceneGameObjects.find(name_) == sceneGameObjects.end())
//	{
//		go_->SetTag(name_);
//		sceneGameObjects[name_] = go_;
//
//	}
//	else
//	{
//		Debug::Error("Trying to add a Gameobject with a name " + name_ + "that already exists", __FILE__, __LINE__);
//	}
//
//}
//
//void SceneGraph::AddCamera(Camera* co_, CAMTYPE camtype_)
//{
//	if (!camtype_)
//	{
//
//		sceneCameras[camtype_] = co_;
//
//	}
//	else if (sceneCameras.find(camtype_) == sceneCameras.end())
//	{
//
//		sceneCameras[camtype_] = co_;
//
//	}
//	else
//	{
//		Debug::Error("Trying to add a Gameobject with a name " + camtype_, __FILE__, __LINE__);
//	}
//}
//Camera* SceneGraph::GetCamera(CAMTYPE camtype_)
//{
//	if (sceneCameras.find(camtype_) != sceneCameras.end())
//	{
//		return sceneCameras[camtype_];
//	}
//	return nullptr;
//}
//
//GameObject* SceneGraph::GetGameObject(std::string name_)
//{
//	if (sceneGameObjects.find(name_) != sceneGameObjects.end())
//	{
//		return sceneGameObjects[name_];
//	}
//	return nullptr;
//}
//
//void SceneGraph::Update(const float deltaTime_)
//{
//	for (auto go : sceneGameObjects)
//	{
//		go.second->Update(deltaTime_);
//	}
//}
//
//void SceneGraph::Render()
//{
//	glEnable(GL_DEPTH_TEST);
//	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	for (auto entry : sceneModels)
//	{
//		entry.first->use();
//		for (auto m : entry.second)
//		{
//			m->Render();
//		}
//	}
//	for (auto entry : sceneLights)
//	{
//		entry.first->use();
//		for (auto m : entry.second)
//		{
//			m->Render();
//		}
//	}
//	for (auto entry : sceneGameObjects)
//	{
//		entry.second->GetBoundingBox().Render();
//		
//	}
//	skybox->Render();
//	//terrain->Render();
//
//
//	glBindVertexArray(0);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//}
//
