#include "../../framework.h"
#include "../../environment.h"

std::unique_ptr<Scene> SceneManager::pScene = NULL;
std::unique_ptr<Scene> SceneManager::pReservedScene = NULL;
eSceneTable SceneManager::currentScene = eSceneTable::None;
eSceneTable SceneManager::reservedScene = eSceneTable::Title; //�����V�[��

SceneManager::SceneManager() {
}
SceneManager::~SceneManager() {
}

void SceneManager::SwitchScene(eSceneTable scene) {
	reservedScene = scene;
}
//�V�[���̐؂�ւ�
void SceneManager::SwitchScene() {
	//�؂�ւ��\��̃`�F�b�N
	if (currentScene == reservedScene)
	{
		return;
	}

	//�V�[���폜
	DeleteScene();

	//�V�[���̍쐬
	switch (reservedScene)
	{
	case eSceneTable::Title: pScene = std::make_unique<SceneTitle>(); break;
	case eSceneTable::Game:	pScene = std::make_unique <SceneGame>(); break;
	}

	//���݂̃V�[����ݒ�
	currentScene = reservedScene;

	//�V�[���̏�����
	pScene->Initialize();
}

//�V�[���̍폜
void SceneManager::DeleteScene() {
	if (pScene != NULL)
	{
		//�V�[���̏I��
		pScene.reset();
		pScene = NULL;
	}
}
