#pragma once
//�V�[���N���X��`�t�@�C��
#include "scene.h"
#include "Title/scene_title.h"
#include "Game/scene_game.h"

//�V�[���̎��
enum class eSceneTable
{
	None,
	Title,
	Game,
	SceneMax,
};

class SceneManager {
private:
	static std::unique_ptr<Scene> pScene;
	static std::unique_ptr<Scene> pReservedScene;

	static eSceneTable currentScene;
	static eSceneTable reservedScene;

public:
	SceneManager();
	~SceneManager();

	//�V�[���̗\��
	static void SwitchScene(eSceneTable scene);
	//�V�[���̐؂�ւ�
	static void SwitchScene();

	//�V�[���̍폜
	static void DeleteScene();

	//Getter,Setter
	static std::unique_ptr<Scene> &GetCurrentScene() { return pScene; }
};