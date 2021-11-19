#include "../../framework.h"
#include "../../environment.h"

std::unique_ptr<Scene> SceneManager::pScene = NULL;
std::unique_ptr<Scene> SceneManager::pReservedScene = NULL;
eSceneTable SceneManager::currentScene = eSceneTable::None;
eSceneTable SceneManager::reservedScene = eSceneTable::Title; //初期シーン

SceneManager::SceneManager() {
}
SceneManager::~SceneManager() {
}

void SceneManager::SwitchScene(eSceneTable scene) {
	reservedScene = scene;
}
//シーンの切り替え
void SceneManager::SwitchScene() {
	//切り替え予約のチェック
	if (currentScene == reservedScene)
	{
		return;
	}

	//シーン削除
	DeleteScene();

	//シーンの作成
	switch (reservedScene)
	{
	case eSceneTable::Title: pScene = std::make_unique<SceneTitle>(); break;
	case eSceneTable::Game:	pScene = std::make_unique <SceneGame>(); break;
	}

	//現在のシーンを設定
	currentScene = reservedScene;

	//シーンの初期化
	pScene->Initialize();
}

//シーンの削除
void SceneManager::DeleteScene() {
	if (pScene != NULL)
	{
		//シーンの終了
		pScene.reset();
		pScene = NULL;
	}
}
