#include "Scene.h"

int SubScene::Switch(const int scene) {
	return scene;
}

void SubScene::Update(const int scene) {
	nowScene = scene;
	ContentUpdate();
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

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//�\��
void Scene::View() {
	if (loadFlag == 2)
		SubScene::View();
}

//�폜
void Scene::Delete() {
	ContentDelete();
	loadFlag = 0;
}