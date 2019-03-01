//#include "CollisionHandler.h"
//#include "../Core/EngineClass.h"
//#include <algorithm>  
//
//std::unique_ptr<CollisionHandler> CollisionHandler::collisionInstance = nullptr;
//
////std::vector<GameObject*> CollisionHandler::colliders = std::vector<GameObject*>();
//std::vector<GameObject*> CollisionHandler::previousCollisions = std::vector<GameObject*>();
//
//CollisionHandler::CollisionHandler()
//{
//}
//
//
//CollisionHandler::~CollisionHandler()
//{
//	delete ScenePartition;
//	ScenePartition = nullptr;
//}
//
//
//CollisionHandler* CollisionHandler::GetInstance() {
//
//	if (collisionInstance.get() == nullptr) {
//		collisionInstance.reset(new CollisionHandler);
//	}
//	return collisionInstance.get();
//}
//
//void CollisionHandler::AddObject(GameObject* go_) {
//	//colliders.push_back(go_);
//	ScenePartition->AddObject(go_);
//}
//
//void CollisionHandler::Update(glm::vec2 mousePosition_, int buttonType_) {
//
//	//Lab needs to be here
//	Ray ray = CollisionDetection::ScreenToWorldRay(mousePosition_, EngineClass::GetInstance()->GetScreenSize());
//	GameObject* hitResult = ScenePartition->GetCollision(ray);
//
//	if (hitResult)
//	{
//		hitResult->SetHit(true, buttonType_);
//	}
//
//	for (auto c : previousCollisions)
//	{
//		if (hitResult != c && c != nullptr)
//		{
//			c->SetHit(false, buttonType_);
//		}
//	}
//	previousCollisions.clear();
//	if (hitResult)
//	{
//		previousCollisions.push_back(hitResult);
//	}
//
//}
//
//void CollisionHandler::Initialize(float worldSize_) {
//	previousCollisions.clear();
//	previousCollisions.shrink_to_fit();
//
//	ScenePartition = new OctSpatialPartition(worldSize_);
//}
