#include "../../framework.h"
#include "../../environment.h"

//初期化
bool SceneTitle::Initialize() {
	sprite = CreateSprite<Sprite>(new Sprite(500, 300, 200, 200, L"Data/Image/sample.png"));
	sprite->SetRenderPriority(2);
	sprite->vtx[0].a = 0.2f;
	sprite2 = CreateSprite<Sprite>(new Sprite(100, 300, 200, 200, L"Data/Image/sample.png"));
	sound0 = CreateSound(new Sound(L"Data/Sound/title_bgm.wav"));
	sound0->Play();

	return true;
}

void SceneTitle::Terminate() {

}

//処理
void SceneTitle::Execute() {
	if (Keyboard::On(DIK_SPACE)) {
		switchScene(eSceneTable::Game);
	}

	if (Joystick::GetLX()) {
		sprite2->posX += Joystick::GetLX() * 2;
	}

	if (Joystick::Trg(JOY_SQUARE)) {
		sprite->isRenderEnable() ? sprite->SetRenderEnable(false) : sprite->SetRenderEnable(true);
	}

	if (Joystick::Trg(JOY_CIRCLE)) {
		sprite->SetRenderPriority(-1);
	}
	if (Joystick::Trg(JOY_TRIANGLAR)) {
		sprite->SetRenderPriority(2);
	}

	Font::Print(900, 500, L"%f, %f", Joystick::GetLX(), Joystick::GetLY());
	Font::SetRect(200, 100, 500, WINDOW_HEIGHT);
	Font::SetTextAlignment(DWRITE_TEXT_ALIGNMENT::DWRITE_TEXT_ALIGNMENT_CENTER);
	Font::SetColor(0xffffffff);
	Font::Print(L"変更後　%d ", Joystick::PovOn(18000));
	Font::SetColor(0xff88ff88);
	Font::Print(200, 130, L"vvv　%d ", Joystick::PovOn(18000));
	Font::Print(200, 160, L"vvv　%d ", Joystick::PovOn(18000));
	Font::SetRect();

	Scene::Execute();
}

//描画
void SceneTitle::Render() {
	Scene::Render();
}
