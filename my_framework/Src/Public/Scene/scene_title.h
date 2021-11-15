#pragma once

class SceneTitle : public Scene {
private:
	noDel_ptr<Sprite> sprite;
	noDel_ptr<Sprite> sprite2;
	noDel_ptr<Sound> sound0;
	noDel_ptr<Sprite> sp;
	std::unique_ptr<Sprite>usp;

private:
	//‰Šú‰»
	bool Initialize();

	//íœ
	void Terminate();

	//ˆ—
	void Execute();

	//•`‰æ
	void Render();
};