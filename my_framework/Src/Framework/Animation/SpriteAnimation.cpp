#include "../../framework.h"
#include "../../environment.h"

//��x���ׂĂ̔z��̏���������
SpriteAnimation::SpriteAnimation(Sprite* pSprite, bool loop) {
	showSprite = pSprite; //���ݕ\������X�v���C�g
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
	//�e�L�[�t���[�����ƍ�����
	for (int i = 0; i < keyFrame.size(); i++) {
		if (currentKeyFlameIndex >= i) continue; //���B���Ă���L�[�t���[����菬�����ꍇ�͂Ƃ΂�
		if (keyFrame[i]->flame < flameCount) { //�����B�w��L�[�t���[������茻�݂̌o�߃t���[�������傫���ꍇ
			if (i == keyFrame.size() - 1) {
				if (isLoop) AnimLoop();
				else AnimOff();
				return;
			}
			continue;
		}

		//�t���[�����������ꍇ�A�S�Ă̏�Ԃ�ύX
		if (flameCount == keyFrame[i]->flame) {
			currentKeyFlameIndex = i;

			//�X�v���C�g��ԕύX
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

			//�L�[�t���[���̍Ō�ɓ��B�����ꍇ
			if (currentKeyFlameIndex == keyFrame.size() - 1) {
				if (isLoop) AnimLoop();
				else AnimOff();
 				return;
			}

			break;
		}

		//
		//���̃L�[�t���[���Ɍ����ď��X�ɏ�Ԃ�J��
		// 
		
		if (currentKeyFlameIndex < 0) break; //�����l�̏ꍇ�I��

		//���̃L�[�t���[���܂ł̐i������(���݂̃t���[����-���B���Ă���L�[�t���[����) / (���̃L�[�t���[����-���B���Ă���L�[�t���[����)
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

	flameCount++; //�t���[���J�E���g�X�V
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