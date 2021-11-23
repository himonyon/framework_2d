/*-----------------------------------------------------------

	Mainクラス
		ゲーム全体の処理の流れを管理

-------------------------------------------------------------*/

#pragma once
#include "../../framework.h"
#include "../../environment.h"

class Main {
public:
	bool Init(void* hWnd);
	void Destroy();
	void App();
	void Execute();
	void Render();
};