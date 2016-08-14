#include "Scene.h"

//��ʂ̐؂�ւ�
int SubScene::Switch(const int scene) {
	return scene;
}

//�v�Z
void SubScene::Update(const int scene) {
	nowScene = scene;
	ContentUpdate();
}

void SubScene::Load() {
	viewFlag = TRUE;
}

void SubScene::Delete() {
	viewFlag = FALSE;
}

//�\��
void SubScene::View() {
	if (viewFlag)
		ContentView();
}

//���[�h
void Scene::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		ContentLoad();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0) {
		viewFlag = TRUE;
		loadFlag = 2;
	}
}

//�\��
void Scene::View() {
	if (loadFlag == 2)
		SubScene::View();
}

//�폜
void Scene::Delete() {
	ContentDelete();
	viewFlag = FALSE;
	loadFlag = 0;
}