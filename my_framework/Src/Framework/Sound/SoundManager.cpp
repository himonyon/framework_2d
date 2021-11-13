#include "../../../framework.h"
#include "../../../environment.h"

Sound* SoundManager::CreateSound(Sound* instance) {
	sounds.emplace_back(instance);
	Sound* p = sounds.back();
	return p;
}