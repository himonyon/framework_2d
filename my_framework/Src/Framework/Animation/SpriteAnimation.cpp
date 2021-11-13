#include "../../framework.h"
#include "../../environment.h"

//一度すべての配列の情報を初期化
SpriteAnimation::SpriteAnimation(Sprite* pSprite, bool loop) {
	showSprite = pSprite; //現在表示するスプライト
	isLoop = loop;

	if (pScene != NULL) {
		pScene->RegisterAnimation(this);
	}
}

void SpriteAnimation::CreateKeyFlame(int keyNum) {
	for (int i = 0; i < keyNum + 1; i++) {
		if (i < keyFrame.size()) continue;
		keyFrame.emplace_back(new KeyFlame());

		keyFrame[i]->flame = 0;
		keyFrame[i]->pSprite = showSprite;
		keyFrame[i]->x = showSprite->posX;
		keyFrame[i]->y = showSprite->posY;
		keyFrame[i]->r = showSprite->vtx[0].r;
		keyFrame[i]->g = showSprite->vtx[0].g;
		keyFrame[i]->b = showSprite->vtx[0].b;
		keyFrame[i]->a = showSprite->vtx[0].a;
		keyFrame[i]->scaleX = showSprite->scaleX;
		keyFrame[i]->scaleY = showSprite->scaleY;
		keyFrame[i]->rot = showSprite->rot;
	}
}

void SpriteAnimation::AnimOn() {
	//各キーフレームを照合する
	for (int i = 0; i < keyFrame.size(); i++) {
		if (currentKeyFlameIndex >= i) continue; //到達しているキーフレームより小さい場合はとばす
		if (keyFrame[i]->flame < flameCount) { //未到達指定キーフレーム数より現在の経過フレーム数が大きい場合
			if (i == keyFrame.size() - 1) {
				if (isLoop) AnimLoop();
				else AnimOff();
				return;
			}
			continue;
		}

		//フレーム数が同じ場合、全ての状態を変更
		if (flameCount == keyFrame[i]->flame) {
			currentKeyFlameIndex = i;

			//スプライト状態変更
			if (keyFrame[i]->pSprite != showSprite) {
				showSprite->SetRenderEnable(false);
				keyFrame[i]->pSprite->SetRenderEnable(true);
				showSprite = keyFrame[i]->pSprite;
			}

			if (showSprite->isRenderEnable() == false) showSprite->SetRenderEnable(true);

			showSprite->SetPosition(keyFrame[i]->x, keyFrame[i]->y);
			showSprite->SetColor(keyFrame[i]->r, keyFrame[i]->g, keyFrame[i]->b, keyFrame[i]->a);
			showSprite->SetScale(keyFrame[i]->scaleX, keyFrame[i]->scaleY);
			showSprite->rot = keyFrame[i]->rot;

			//キーフレームの最後に到達した場合
			if (currentKeyFlameIndex == keyFrame.size() - 1) {
				if (isLoop) AnimLoop();
				else AnimOff();
 				return;
			}

			break;
		}

		//
		//次のキーフレームに向けて徐々に状態を遷移
		// 
		
		if (currentKeyFlameIndex < 0) break; //初期値の場合終了

		//次のキーフレームまでの進捗割合(現在のフレーム数-到達しているキーフレーム数) / (次のキーフレーム数-到達しているキーフレーム数)
		float rate = (flameCount - keyFrame[currentKeyFlameIndex]->flame) / 
			(keyFrame[i]->flame - keyFrame[currentKeyFlameIndex]->flame);

		//pos
		float move_x = (keyFrame[i]->x - keyFrame[currentKeyFlameIndex]->x) * rate;
		showSprite->posX = keyFrame[currentKeyFlameIndex]->x + move_x;
		float move_y = (keyFrame[i]->y - keyFrame[currentKeyFlameIndex]->y) * rate;
		showSprite->posY = keyFrame[currentKeyFlameIndex]->y + move_y;

		//col
		float r_diff = (keyFrame[i]->r - keyFrame[currentKeyFlameIndex]->r) * rate;
		float g_diff = (keyFrame[i]->g - keyFrame[currentKeyFlameIndex]->g) * rate;
		float b_diff = (keyFrame[i]->b - keyFrame[currentKeyFlameIndex]->b) * rate;
		float a_diff = (keyFrame[i]->a - keyFrame[currentKeyFlameIndex]->a) * rate;
		showSprite->SetColor(keyFrame[currentKeyFlameIndex]->r + r_diff, keyFrame[currentKeyFlameIndex]->g + g_diff,
			keyFrame[currentKeyFlameIndex]->b + b_diff, keyFrame[currentKeyFlameIndex]->a + a_diff);

		//scale
		float scaleX_diff = (keyFrame[i]->scaleX - keyFrame[currentKeyFlameIndex]->scaleX) * rate;
		float scaleY_diff = (keyFrame[i]->scaleY - keyFrame[currentKeyFlameIndex]->scaleY) * rate;
		showSprite->SetScale(keyFrame[currentKeyFlameIndex]->scaleX + scaleX_diff,
			keyFrame[currentKeyFlameIndex]->scaleY + scaleY_diff);

		//rot
		float rot_diff = (keyFrame[i]->rot - keyFrame[currentKeyFlameIndex]->rot) * rate;
		showSprite->rot = keyFrame[currentKeyFlameIndex]->rot + rot_diff;

		break;
	}

	flameCount++; //フレームカウント更新
}

void SpriteAnimation::AnimOff() {
	animEnable = false;
	flameCount = 0;
	currentKeyFlameIndex = -1;
}
void SpriteAnimation::AnimLoop() {
	flameCount = 0;
	currentKeyFlameIndex = -1;
}


bool SpriteAnimation::isAnimEnable() {
	return animEnable;
}
void SpriteAnimation::SetAnimEnable(bool flag) {
	animEnable = flag;
}

void SpriteAnimation::SetKeyFlameSprite(int index, Sprite* sprite) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->pSprite = sprite;
}
void SpriteAnimation::SetKeyFlameSprite(int index, Sprite* sprite, float flame) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->pSprite = sprite;
	keyFrame[index]->flame = flame;
}

void SpriteAnimation::SetKeyFlamePos(int index, float x, float y) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->x = x;
	keyFrame[index]->y = y;
}
void SpriteAnimation::SetKeyFlamePos(int index, float x, float y, float flame) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->x = x;
	keyFrame[index]->y = y;
	keyFrame[index]->flame = flame;
}

void SpriteAnimation::SetKeyFlameCol(int index, float r, float g, float b, float a) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->r = r;
	keyFrame[index]->g = g;
	keyFrame[index]->b = b;
	keyFrame[index]->a = a;
}
void SpriteAnimation::SetKeyFlameCol(int index, float r, float g, float b, float a, float flame) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->r = r;
	keyFrame[index]->g = g;
	keyFrame[index]->b = b;
	keyFrame[index]->a = a;
	keyFrame[index]->flame = flame;
}

void SpriteAnimation::SetKeyFlameScale(int index, float x, float y) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->scaleX = x;
	keyFrame[index]->scaleY = y;
}
void SpriteAnimation::SetKeyFlameScale(int index, float x, float y, float flame) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->scaleX = x;
	keyFrame[index]->scaleY = y;
	keyFrame[index]->flame = flame;
}

void SpriteAnimation::SetKeyFlameRot(int index, float rot) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->rot = rot;
}
void SpriteAnimation::SetKeyFlameRot(int index, float rot, float flame) {
	if (index >= keyFrame.size()) CreateKeyFlame(index);
	keyFrame[index]->rot = rot;
	keyFrame[index]->flame = flame;
}