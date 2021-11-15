#pragma once

class SceneGame : public Scene{
private:
	noDel_ptr<Sprite> sprite;
	noDel_ptr<Sound> sound0;
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