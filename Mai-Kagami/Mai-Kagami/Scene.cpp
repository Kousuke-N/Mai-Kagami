#include "Scene.h"

//ロード
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

//更新
void Scene::Update() {
	Load();
	if (loadFlag == 2)
		ContentUpdate();
}

//表示
void Scene::View() {
	if (loadFlag == 2)
		ContentView();
}

//削除
void Scene::Delete() {
	ContentDelete();
	loadFlag = 0;
}