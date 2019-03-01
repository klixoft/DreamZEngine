//#ifndef SCENEGRAPH_H
//#define SCENEGRAPH_H
//
//
//
//#include "../Camera/Camera.h"
//
//#include "../Rendering/3D/GameObject.h"
//
//enum CAMTYPE {
//	MAIN,
//	TOPDOWN,
//	THIRDPERSON
//};
//
//class SceneGraph
//{
//public:
//	SceneGraph(const SceneGraph&) = delete;
//	SceneGraph(SceneGraph&&) = delete;
//	SceneGraph& operator=(const SceneGraph&) = delete;
//	SceneGraph& operator=(SceneGraph&&) = delete;
//
//	static SceneGraph* GetInstance();
//	void Update(const float deltaTime_);
//
//	void AddModel(Model* model_);
//	void AddCollider(Cube* cube_);
//	void AddLight(BasicLight* model_, std::string name_, LightStruct* lightstruct_);
//	void AddSkybox(SkyBox* skybox_);
//	void AddTerain(Terrain * terrain_);
//	void AddGameObject(GameObject* go_, std::string name_ = "");
//	GameObject* GetGameObject(std::string name_);
//	void AddCamera(Camera* go_, CAMTYPE camtype_ = CAMTYPE::MAIN);
//	Camera* GetCamera(CAMTYPE camtype_);
//	void Render();
//
//
//private:
//	SceneGraph();
//	~SceneGraph();
//	
//	SkyBox* skybox;
//	Terrain* terrain;
//
//	static std::unique_ptr<SceneGraph> sceneGraphInstance;
//	friend std::default_delete<SceneGraph>;
//	
//	static std::map<Shader*, std::vector<BasicLight*>> sceneLights;
//	static std::map<Shader*, std::vector<Cube*>> sceneColliders;
//	static std::map<Shader*, std::vector<Model*>> sceneModels;
//	static std::map<std::string, GameObject*> sceneGameObjects;
//	static std::map<CAMTYPE, Camera*> sceneCameras;
//};
//
//
//
//#endif // !SCENEGRAPH_
//
