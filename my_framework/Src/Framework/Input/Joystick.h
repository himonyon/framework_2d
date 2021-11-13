#pragma once

class Joystick {
public:
	//�W���C�X�e�B�b�N(0~)
	static bool IsValid();
	static bool On(int button);
	static bool Trg(int button);
	static bool Rel(int button);
	static float GetLX();
	static float GetLY();
	static float GetRX();
	static float GetRY();
	static bool PovOn(int pov);
	static bool PovTrg(int pov);
	static bool PovRel(int pov);
};
