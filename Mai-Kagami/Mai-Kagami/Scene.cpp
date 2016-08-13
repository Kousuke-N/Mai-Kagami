#include "Scene.h"

//���[�h
void Scene::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		ContentLoad();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//�X�V
int Scene::Update(const int scene) {
	Load();
	if (loadFlag == 2)
		return ContentUpdate();
	return scene;
}

//�\��
void Scene::View() {
	if (loadFlag == 2)
		ContentView();
}

//�폜
void Scene::Delete() {
	ContentDelete();
	loadFlag = 0;
}