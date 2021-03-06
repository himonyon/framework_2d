#include "../../framework.h"
#include "../../environment.h"

//初期化
bool SceneGame::Initialize() {
	pSample0 = noDel_ptr<GameObject2D>(CreateObject2D<GameObject2D>(
		new GameObject2D(10, 10, 200, 200, 
			CreateSprite(L"Data/Image/sample.png",0.5f))));

	pSound0 = noDel_ptr<Sound>(CreateSound(L"Data/Sound/title_bgm.wav"));
	pSound0->Play();

	return true;
}

void SceneGame::Terminate() {

}

//処理
void SceneGame::Execute() {
	if (Input::Trg(InputConfig::cancel)) {
		SceneManager::SwitchScene(eSceneTable::Title);
	}

	Scene::Execute();
}

//描画
void SceneGame::Render() {
	Scene::Render();
}
