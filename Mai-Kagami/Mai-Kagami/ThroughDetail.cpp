#include "ThroughDetail.h"

ThroughDetail::ThroughDetail(Font *font) {
	title = new DrawTitle(font, "�̓_����");
	button = new CircleButton2(font, "����", 4);
}

void ThroughDetail::View() {
	title->View();
	button->View();
}

ThroughDetail::~ThroughDetail() {
	delete title;
	delete button;
}