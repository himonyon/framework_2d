#include "../../framework.h"
#include "../../environment.h"

//初期化
bool SceneGame::Initialize() {
	sprite = CreateSprite<Sprite>(new Sprite(10, 10, 200, 200, L"Data/Image/sample.png"));
	sprite->vtx[0].a = 0.2f;
	sound0 = CreateSound(new Sound(L"Data/Sound/title_bgm.wav"));
	sound0->Play();

	return true;
}

void SceneGame::Terminate() {

}

//処理
void SceneGame::Execute() {
	if (Mouse::Trg(1)) {
		switchScene(eSceneTable::Title);
	}


	Scene::Execute();
}

//描画
void SceneGame::Render() {
	Scene::Render();
}
