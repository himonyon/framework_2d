#pragma once

class SoundManager {
public:
	SoundManager() {}
	~SoundManager(){
		for (auto& sd : sounds) {
			delete sd;
		}
		sounds.clear();
	}

	Sound* CreateSound(Sound* instance) {
		sounds.emplace_back(instance);
		Sound* p = sounds.back();
		return p;
	}

private:
	std::vector<Sound*> sounds;
};
