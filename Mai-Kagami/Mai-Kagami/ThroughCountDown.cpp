#include "ThroughCountDown.h"


//�J�E���g�_�E����ʍĐ��O�p�`
PlayTriangle::PlayTriangle(const float x, const float y)
	: MyDrawTriangle("Yellow") {
	const float w = 100, ex = 12;
	float x1 = x - w + ex, x2 = x - w + ex, x3 = x + w + ex;
	float y1 = y + w, y2 = y - w, y3 = y;
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//�J�E���g�_�E�����
ThroughCountDown::ThroughCountDown(Font *font) {
	const float x = WIDTH * 0.5; //�~�̒��S�ix���W�j
	const float y = HEIGHT * 0.5; //�~�̒��S�iy���W�j
	const float r = WIDTH * 0.2; //�~�̔��a
	blackBox = new BlackBox();
	text = new MyDrawText(font, "���������Ă�������", x, y + r + 80, 1, 40);
	circle = new MyDrawCircle(x, y, r, "White");
	circle->SetAlpha(220);
	countCircle1 = new MyDrawCircleGauge(x, y, r, 0, 4, "Yellow");
	countCircle2 = new MyDrawCircle(0, 0, 12, "Yellow");
	playTriangle = new PlayTriangle(x, y);
}

int ThroughCountDown::Switch(const int scene) {
	if (++count == max)
		return THROUGH_PLAY;
	return scene;
}

void ThroughCountDown::ContentUpdate() {
	static int lastScene = -100;
	if (nowScene == THROUGH_COUNTDOWN) {
		viewFlag = TRUE;
		countCircle1->ChangeDegree((double)count / max * 100);
		countCircle2->ChangePos(countCircle1->GetEndX() * SIZE_RATE, countCircle1->GetEndY() * SIZE_RATE);
	}
	else {
		count = 0;
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

void ThroughCountDown::ContentView() {
	blackBox->View();
	text->View();
	circle->View();
	countCircle1->View();
	countCircle2->View();
	playTriangle->View();
}

ThroughCountDown::~ThroughCountDown() {
	delete blackBox;
	delete text;
	delete circle;
	delete countCircle1;
	delete countCircle2;
	delete playTriangle;
}
