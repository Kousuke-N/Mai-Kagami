#include "Scene.h"

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

//�X�V
void Scene::Update() {
	Load();
	if (loadFlag == 2)
		ContentUpdate();
}

//�\��
void Scene::View() {
	if(viewFlag && loadFlag == 2)
		ContentView();
}

//�폜
void Scene::Delete() {
	ContentDelete();
	loadFlag = 0;
}