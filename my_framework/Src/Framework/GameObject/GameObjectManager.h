#pragma once

class GameObjectManager {
public:
	GameObjectManager() {};
	~GameObjectManager();

	template<class T>
	T* CreateObject2D(GameObject2D* instance) {
		objects2d.emplace_back(instance);
		return dynamic_cast<T*>(objects2d.back());
	}

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
