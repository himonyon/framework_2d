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

	Sound* CreateSound(Sound* instance);

private:
	std::vector<Sound*> sounds;
};
