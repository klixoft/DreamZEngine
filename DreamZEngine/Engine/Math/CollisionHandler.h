//#ifndef COLLISIONHANDLER_H
//#define COLLISIONHANDLER_H
//
//#include "CollisionDetection.h"
//#include "../Rendering/3D/GameObject.h"
//#include "Ray.h"
//#include "../Core/OctSpatialPartition.h"
//
//
//class CollisionHandler
//{
//public:
//
//	CollisionHandler(const Camera&) = delete;
//	CollisionHandler(CollisionHandler&&) = delete;
//	CollisionHandler& operator=(const CollisionHandler&) = delete;
//	CollisionHandler& operator=(CollisionHandler&&) = delete;
//
//	static CollisionHandler* GetInstance();
//	
//	void AddObject(GameObject* go_);
//	void Update(glm::vec2 mousePosition_, int buttonType_);
//	void Initialize(float worldSize_);
//
//private:
//	CollisionHandler();
//	~CollisionHandler();
//
//	static std::unique_ptr<CollisionHandler> collisionInstance;
//	friend std::default_delete<CollisionHandler>;
//
//	//static std::vector<GameObject*> colliders;
//	static std::vector<GameObject*> previousCollisions;
//
//	OctSpatialPartition* ScenePartition;
//};
//
//#endif
