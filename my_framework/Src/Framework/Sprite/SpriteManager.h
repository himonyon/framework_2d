#pragma once

class SpriteManager {
public:
	SpriteManager() {};
	~SpriteManager() {
		for (auto& sprite : sprites) {
			delete sprite;
		}
		sprites.clear();
	}

	template<class T>
	T* CreateSprite(Sprite* instance) {
		sprites.emplace_back(instance);
		T* p = dynamic_cast<T*>(sprites.back());
		return p;
	}

	//����
	void Execute();
	//�`��
	void Render();

private:
	//�`�揇�̕ύX(�N�C�b�N�\�[�g)
	void RenderOrderSort(int start, int end);

private:
	int count = 0;
	std::vector<Sprite*> sprites;
};
