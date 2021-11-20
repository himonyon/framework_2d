#pragma once

/// <summary>
/// �L�[�{�[�h�A�W���C�X�e�B�b�N�̃��[�U�[�ݒ�p�N���X
/// �L�[�{�[�h�ƃW���C�X�e�B�b�N�̊e�{�^���ɋ��ʂ̖�������������
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