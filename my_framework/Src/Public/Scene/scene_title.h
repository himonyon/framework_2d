#pragma once

class SceneTitle : public Scene {
private:
	noDel_ptr<Sprite> sprite;
	noDel_ptr<Sprite> sprite2;
	noDel_ptr<Sound> sound0;
	noDel_ptr<Sprite> sp;
	std::unique_ptr<Sprite>usp;

private:
	//������
	bool Initialize();

	//�폜
	void Terminate();

	//����
	void Execute();

	//�`��
	void Render();
};