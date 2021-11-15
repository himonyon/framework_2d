#include "../../../framework.h"
#include "../../../environment.h"

bool Joystick::IsValid() {
	return DirectInput::IsJoystickEnable();
}
bool Joystick::On(int button) {
	return (DirectInput::GetCurrentJoystick().rgbButtons[button] != 0);
}
bool Joystick::Trg(int button) {
	return (DirectInput::GetCurrentJoystick().rgbButtons[button] != 0 && DirectInput::GetOldJoystick().rgbButtons[button] == 0);
}
bool Joystick::Rel(int button) {
	return (DirectInput::GetCurrentJoystick().rgbButtons[button] == 0 && DirectInput::GetOldJoystick().rgbButtons[button] != 0);
}
float Joystick::GetLX() {
	return DirectInput::GetCurrentJoystick().lX * DirectInput::GetJoyAxisRange();
}
float Joystick::GetLY() {
	return DirectInput::GetCurrentJoystick().lY * DirectInput::GetJoyAxisRange();
}
float Joystick::GetRX() {
	return DirectInput::GetCurrentJoystick().lZ * DirectInput::GetJoyAxisRange();
}
float Joystick::GetRY() {
	return DirectInput::GetCurrentJoystick().lRz * DirectInput::GetJoyAxisRange();
}
bool Joystick::PovOn(int pov) {
	return DirectInput::GetCurrentJoystick().rgdwPOV[0] == pov;
}
bool Joystick::PovTrg(int pov) {
	return DirectInput::GetCurrentJoystick().rgdwPOV[0] == pov && DirectInput::GetOldJoystick().rgdwPOV[0] != pov;
}
bool Joystick::PovRel(int pov) {
	return DirectInput::GetCurrentJoystick().rgdwPOV[0] != pov && DirectInput::GetOldJoystick().rgdwPOV[0] == pov;
}