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

	//処理
	void Execute();
	//描画
	void Render();

private:
	//描画順の変更(クイックソート)
	void RenderOrderSort(int start, int end);

private:
	int count = 0;
	std::vector<Sprite*> sprites;
};
