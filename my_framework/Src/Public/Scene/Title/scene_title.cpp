#include "../../framework.h"
#include "../../environment.h"

//初期化
bool SceneTitle::Initialize() {
	pSp0 = CreateSprite(L"Data/Image/bg.jpg");
	pObj1 = CreateObject2D(500, 300, 200, 200, CreateSprite(L"Data/Image/sample.png"));
	pObj1->SetRenderPriority(2);
	pObj1->pRenderSprite->vtx[0].a = 0.2f;
	pObj2 = CreateObject2D(100, 300, 200, 200, CreateSprite(L"Data/Image/sample.png"));
	pSound0 = CreateSound(L"Data/Sound/title_bgm.wav");
	pSound0->Play();

	pAnim = CreateAnimation(pObj2, true);
	pAnim->SetKeyFrameRot(0, 0, 0);
	pAnim->SetKeyFrameRot(1, 3.14f, 30);
	pAnim->SetKeyFrameSprite(1, pSp0, 30);
	pAnim->SetKeyFrameRot(2, 6.24f, 60);
	pAnim->SetAnimEnable(true);
	return true;
}

void SceneTitle::Terminate() {
}

//処理
void SceneTitle::Execute() {
	if (Input::Trg(InputConfig::Decide)) {
		switchScene(eSceneTable::Game);
	}

	if (IsCollide2D(pObj1, pObj2) != eCollideState::None) {
		Font::Print(600,600,L"当たってんで");
	}

	if (Joystick::GetLX() && Joystick::On(JOY_R)) {
		pObj1->rot.z += Joystick::GetLX() / 2;
	}
	else if (Joystick::GetLX() && Joystick::On(JOY_L)) {
		pObj1->scale.x += Joystick::GetLX() /2 ;
		pObj1->scale.y -= Joystick::GetLY() /2 ;
	}
	else if (Joystick::GetLX()) {
		pObj1->position.x += Joystick::GetLX() * 2;
		pObj1->position.y += Joystick::GetLY() * 2;
	}

	if (Joystick::Trg(JOY_SQUARE)) {
		pObj1->isRenderEnable() ? pObj1->SetRenderEnable(false) : pObj1->SetRenderEnable(true);
	}

	if (Joystick::Trg(JOY_CROSS)) {
		pObj1->SetRenderPriority(-1);
	}
	if (Joystick::Trg(JOY_TRIANGLAR)) {
		pObj1->SetRenderPriority(2);
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
