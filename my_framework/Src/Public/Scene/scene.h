#pragma once

#define MaxSounds (50) //1シーンのサウンドの最大数
#define MaxSprites (256) //１シーンに管理できる画像数
#define MaxAnimation (64) //１シーンに管理できるアニメーション

class Scene : public SpriteManager, public SoundManager {
private:

	std::vector<SpriteAnimation*> pSpriteAnimation_array;

public:
	//コンストラクタ
	Scene();

	//デストラクタ
	virtual ~Scene();

	//初期化
	virtual bool Initialize() = 0;

	virtual void Terminate() = 0;

	//処理
	virtual void Execute();

	//描画
	virtual void Render();

	bool RegisterAnimation(SpriteAnimation* anim);

	//当たり判定
	static bool isCollider(Sprite* collider, float x, float y); //画像と座標
	static bool isCollider(Sprite* collider, int x, int y); //画像と座標
};