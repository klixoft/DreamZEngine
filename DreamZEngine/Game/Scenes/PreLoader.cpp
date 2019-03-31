//#include "PreLoader.h"
//
//
//
//PreLoader::PreLoader() {}
//
//
//PreLoader::~PreLoader()
//{
//}
//
//bool PreLoader::Initialize()
//{
//	
//	sceneManager = EngineClass::GetInstance()->GetSceneManager();
//	// Load shaders
//	defaultShader = new Shader("Engine/Shaders/model.vs", "Engine/Shaders/model.fs");
//	
//	
//	
//	// Put shaders into shader manager
//	test = new DemoUnit();
//	test->SetWorldScale(0.5f);
//	test->SetShader(defaultShader);
//	test->SetWorldPosition(glm::vec3(-2.0f, 0.0f, 3.0f));
//	test->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER1);
//	test->SetPlayerTeam(Player::PLAYERTEAM::TEAM1);
//	unitList.push_back(test);
//	//	player1->GetPlayerInput()->AddAnyController();
//
//
//	// Player 2
//	nanosuit = new BaseUnit_0();
//	nanosuit->SetShader(defaultShader);
//	nanosuit->SetWorldPosition(glm::vec3(2.0f, 0.0f, 3.0f));
//	nanosuit->SetPlayerNumber(Player::PLAYERNUMBER::PLAYER2);
//	nanosuit->SetPlayerTeam(Player::PLAYERTEAM::TEAM1);
//	nanosuit->SetWorldScale(0.5f);
//	unitList.push_back(nanosuit);
//
//
//	sceneManager->NextScene();
//	
//
//
//	return true;
//}
