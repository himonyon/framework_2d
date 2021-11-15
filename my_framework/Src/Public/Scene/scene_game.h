#pragma once

class SceneGame : public Scene{
private:
	noDel_ptr<Sprite> sprite;
	noDel_ptr<Sound> sound0;
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