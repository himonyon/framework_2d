#include "../../../framework.h"
#include "../../../environment.h"

bool Joystick::IsValid() {
	return Input::IsJoystickEnable();
}
bool Joystick::On(int button) {
	return (Input::GetCurrentJoystick().rgbButtons[button] != 0);
}
bool Joystick::Trg(int button) {
	return (Input::GetCurrentJoystick().rgbButtons[button] != 0 && Input::GetOldJoystick().rgbButtons[button] == 0);
}
bool Joystick::Rel(int button) {
	return (Input::GetCurrentJoystick().rgbButtons[button] == 0 && Input::GetOldJoystick().rgbButtons[button] != 0);
}
float Joystick::GetLX() {
	return Input::GetCurrentJoystick().lX * Input::GetJoyAxisRange();
}
float Joystick::GetLY() {
	return Input::GetCurrentJoystick().lY * Input::GetJoyAxisRange();
}
float Joystick::GetRX() {
	return Input::GetCurrentJoystick().lZ * Input::GetJoyAxisRange();
}
float Joystick::GetRY() {
	return Input::GetCurrentJoystick().lRz * Input::GetJoyAxisRange();
}
bool Joystick::PovOn(int pov) {
	return Input::GetCurrentJoystick().rgdwPOV[0] == pov;
}
bool Joystick::PovTrg(int pov) {
	return Input::GetCurrentJoystick().rgdwPOV[0] == pov && Input::GetOldJoystick().rgdwPOV[0] != pov;
}
bool Joystick::PovRel(int pov) {
	return Input::GetCurrentJoystick().rgdwPOV[0] != pov && Input::GetOldJoystick().rgdwPOV[0] == pov;
}