#pragma once

class SceneGame : public Scene{
private:
	noDel_ptr<Sprite> sprite;
	noDel_ptr<Sound> sound0;
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