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

ThroughDetail::ThroughDetail(Font *font, Touch *touch) {
	this->touch = touch;
	title = new DrawTitle(font, "�̓_����");
	button = new CircleButton2(font, "����", 4);
	throughFinish = new ThroughFinish(font);
}

int ThroughDetail::Switch(const int scene) {
	switch (scene)
	{
	case THROUGH_DETAIL:
		if (touch->Get(4) == 1)
			return THROUGH_FINISH;
	case THROUGH_FINISH:
		if (touch->Get(2) == 1)
			return BACK_SONG_SELECT;
		if (touch->Get(3) == 1)
			return BACK_TOP;
	}
	return scene;
}

void ThroughDetail::ContentUpdate() {
	if (nowScene == THROUGH_DETAIL || nowScene == THROUGH_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughDetail::ContentView() {
	title->View();
	button->View();
	if (nowScene == THROUGH_FINISH)
		throughFinish->View();
}

ThroughDetail::~ThroughDetail() {
	delete title;
	delete button;
	delete throughFinish;
}