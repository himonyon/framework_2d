#pragma once

class GameObjectManager {
public:
	GameObjectManager() {};
	~GameObjectManager();

	noDel_ptr<GameObject2D> CreateObject2D(GameObject2D* instance);
	noDel_ptr<GameObject2D> CreateObject2D(float x, float y, float width, float height,
		noDel_ptr<Sprite> sprite, bool isRender = true, noDel_ptr<GameObject> parent = nullptr);

	//����
	void Execute();
	//�`��
	void Render();

private:
	//�`�揇�̕ύX(�N�C�b�N�\�[�g)
	void RenderOrderSort(int start, int end);

private:
	std::vector<GameObject2D*> objects2d;
};
