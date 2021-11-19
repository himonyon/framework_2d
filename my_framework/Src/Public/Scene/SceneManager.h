#pragma once
//シーンクラス定義ファイル
#include "scene.h"
#include "Title/scene_title.h"
#include "Game/scene_game.h"

//シーンの種類
enum class eSceneTable
{
	None,
	Title,
	Game,
	SceneMax,
};

class SceneManager {
private:
	static std::unique_ptr<Scene> pScene;
	static std::unique_ptr<Scene> pReservedScene;

	static eSceneTable currentScene;
	static eSceneTable reservedScene;

public:
	SceneManager();
	~SceneManager();

	//シーンの予約
	static void SwitchScene(eSceneTable scene);
	//シーンの切り替え
	static void SwitchScene();

	//シーンの削除
	static void DeleteScene();

	//Getter,Setter
	static std::unique_ptr<Scene> &GetCurrentScene() { return pScene; }
};