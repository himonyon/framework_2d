#include "../../framework.h"
#include "../../environment.h"


//コンストラクタ
Scene::Scene()
{
}

//デストラクタ
Scene::~Scene()
{
	for (int i = 0; i < pSpriteAnimation_array.size(); i++) {
		delete pSpriteAnimation_array[i];
		pSpriteAnimation_array[i] = NULL;
		pSpriteAnimation_array.erase(pSpriteAnimation_array.begin() + i);
	}
}

//処理
void Scene::Execute()
{
	//画像の処理
	SpriteManager::Execute();

	//アニメーション処理
	for (int i = 0; i < pSpriteAnimation_array.size(); i++) {
		if (pSpriteAnimation_array[i]->isAnimEnable()) {
			pSpriteAnimation_array[i]->AnimOn();
		}
	}
}

void Scene::Render()
{
	SpriteManager::Render();
}


bool Scene::RegisterAnimation(SpriteAnimation* anim) {
	if (anim == NULL) return false;

	if (pSpriteAnimation_array.size() >= MaxAnimation) return false;
	pSpriteAnimation_array.emplace_back(anim);
	return true;
}


bool Scene::isCollider(Sprite* p, float x, float y) {
	if (x > p->vtx[0].x && x < p->vtx[1].x && y > p->vtx[0].y && y < p->vtx[2].y) {
		return true;
	}

	return false;
}
bool Scene::isCollider(Sprite* p, int x, int y) {
	if (x > p->vtx[0].x && x < p->vtx[1].x && y > p->vtx[0].y && y < p->vtx[2].y) {
		return true;
	}

	return false;
}

