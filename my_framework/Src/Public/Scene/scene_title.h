#pragma once

class SceneTitle : public Scene {
private:
	noDel_ptr<Sprite> sprite;
	noDel_ptr<Sprite> sprite2;
	noDel_ptr<Sound> sound0;
	noDel_ptr<Sprite> sp;
	std::unique_ptr<Sprite>usp;

private:
	//初期化
	bool Initialize();

	//削除
	void Terminate();

	//処理
	void Execute();

	//描画
	void Render();
};