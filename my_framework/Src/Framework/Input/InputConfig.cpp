#include "../../../framework.h"
#include "../../../environment.h"

/// <summary>
/// ユーザー設定インプット情報の初期化
/// </summary>
std::vector<int> InputConfig::decide = {};
std::vector<int> InputConfig::cancel = {};
std::vector<int> InputConfig::cursorUp = {};
std::vector<int> InputConfig::cursorDown = {};

void InputConfig::InitInputConfig() {
	Decide_Init();
	Cancel_Init();
	CursorUp_Init();
	CursorDown_Init();
}

void InputConfig::Decide_Init() {
	decide.emplace_back(DIK_SPACE);
	decide.emplace_back(JOY_CIRCLE);
}
void InputConfig::Cancel_Init() {
	cancel.emplace_back(DIK_BACKSPACE);
	cancel.emplace_back(JOY_CROSS);
}
void InputConfig::CursorUp_Init() {
	cursorUp.emplace_back(DIK_UP);
	cursorUp.emplace_back(JOY_POVU);
	cursorUp.emplace_back(JOY_LSTICKU);
}
void InputConfig::CursorDown_Init() {
	cursorDown.emplace_back(DIK_DOWN);
	cursorDown.emplace_back(JOY_POVD);
	cursorDown.emplace_back(JOY_LSTICKD);
}
