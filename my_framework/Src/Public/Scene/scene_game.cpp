#include "../../framework.h"
#include "../../environment.h"

//‰Šú‰»
bool SceneGame::Initialize() {
	sprite = noDel_ptr<Sprite>(CreateSprite<Sprite>(new Sprite(10, 10, 200, 200, L"Data/Image/sample.png")));
	sprite->vtx[0].a = 0.2f;
	sound0 = noDel_ptr<Sound>(CreateSound(new Sound(L"Data/Sound/title_bgm.wav")));
	sound0->Play();

	return true;
}

void SceneGame::Terminate() {

}

//ˆ—
void SceneGame::Execute() {
	if (Input::Trg(InputConfig::Cansel)) {
		switchScene(eSceneTable::Title);
	}


	Scene::Execute();
}

//•`‰æ
void SceneGame::Render() {
	Scene::Render();
}
