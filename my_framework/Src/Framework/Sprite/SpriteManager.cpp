#include "../../../framework.h"
#include "../../../environment.h"

void SpriteManager::Render() {
	for (auto& sprite : sprites) {
		if (sprite == nullptr) continue;
		if (sprite->isRenderEnable() == false) continue;
		if (sprite->pParent != nullptr && sprite->pParent->isRenderEnable() == false) continue;
		sprite->Render();
	}
}

void SpriteManager::Execute() {
	bool isSorted = false;
	for (auto& sprite : sprites) {
		if (sprite == nullptr) continue;
		if (sprite->isExecuteEnable() == false) continue;
		sprite->Execute();

		//描画順が変更された場合ソート
		if (sprite->isSortEnable()) {
			isSorted = true;
		}
	}

	if (isSorted) RenderOrderSort(0, (int)sprites.size() - 1);
}

void SpriteManager::RenderOrderSort(int start, int end) {
	int left = start;
	int right = end;

	while (sprites[left] == NULL) {
		left++;
	}
	if (right <= left) return;

	int pivot = sprites[left]->GetRenderPriority();

	while (true) {
		while (sprites[left] == NULL) left++;
		while (sprites[right] == NULL) right--;
		while (sprites[left]->GetRenderPriority() < pivot) left++;
		while (sprites[right]->GetRenderPriority() > pivot) right--;

		if (left < right) {
			Sprite* sprite = sprites[left];
			sprites[left] = sprites[right];
			sprites[right] = sprite;

			left++;
			right--;
		}
		else {
			break;
		}
	}

	// 左側再帰
	RenderOrderSort(start, left - 1);
	// 右側再帰
	RenderOrderSort(right + 1, end);
}