#include "ThroughDetail.h"

ThroughFinish::ThroughFinish(Font *font) {
	blackBox = new BlackBox();
	button[0] = new CircleButton(font, "�������ߗ��K", 0, WIDTH * 0.75, "White");
	button[1] = new CircleButton(font, "���K���@�I��", 1, WIDTH * 0.75, "White");
	button[2] = new CircleButton(font, "�ȑI�����", 2, WIDTH * 0.75, "White");
	button[3] = new CircleButton(font, "�I��", 3, WIDTH * 0.75, "White");
}

void ThroughFinish::View() {
	blackBox->View();
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

ThroughFinish::~ThroughFinish() {
	delete blackBox;
	for (int i = 0; i < 4; i++)
		delete button[i];
}

ThroughDetail::ThroughDetail(Font *font) {
	title = new DrawTitle(font, "�̓_����");
	button = new CircleButton2(font, "����", 4);
	throughFinish = new ThroughFinish(font);
}

void ThroughDetail::Update(const int scene) {
	ThroughDetail::scene = scene;
}

void ThroughDetail::View() {
	title->View();
	button->View();
	if (scene == THROUGH_FINISH)
		throughFinish->View();
}

ThroughDetail::~ThroughDetail() {
	delete title;
	delete button;
	delete throughFinish;
}