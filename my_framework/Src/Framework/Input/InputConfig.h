#pragma once

/// <summary>
/// キーボード、ジョイスティックのユーザー設定用クラス
/// キーボードとジョイスティックの各ボタンに共通の役割をもたせる
/// </summary>

class InputConfig {
public:
	static std::vector<int> decide;
	static std::vector<int> cancel;
	static std::vector<int> cursorUp;
	static std::vector<int> cursorDown;

	static void InitInputConfig();
private:
	static void Decide_Init();
	static void Cancel_Init();
	static void CursorUp_Init();
	static void CursorDown_Init();
};