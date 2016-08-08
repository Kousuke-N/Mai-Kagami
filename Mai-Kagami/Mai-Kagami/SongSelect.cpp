#include "SongSelect.h"

//�ȑI����ʃ{�^��������
SongSelectButton::SongSelectButton(Font *font) {
	button[0] = new TriangleButton(font, "�O�̋Ȃ�", 0, 0);
	button[1] = new CircleButton(font, "����", 1);
	button[2] = new TriangleButton(font, "���̋Ȃ�", 1, 2);
	button[3] = new CircleButton2(font, "�I��", 4);
}

//�ȑI����ʃ{�^���\��
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

SongSelectButton::~SongSelectButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}

SongSelectPop::SongSelectPop(Font *font) {
	blackBox = new BlackBox();
	title = new MyDrawText(font, "- �I�� -", WIDTH * 0.75, HEIGHT * 0.4, 1, 40, "Blue");
	message = new MyDrawText(font, "�{���ɏI��\n���܂����H", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	button[0] = new CircleButton(font, "�͂�", 1, WIDTH * 0.75, "White");
	button[1] = new CircleButton(font, "������", 2, WIDTH * 0.75, "White");
}

void SongSelectPop::View() {
	blackBox->View();
	title->View();
	message->View();
	for (int i = 0; i < 2; i++)
		button[i]->View();
}

SongSelectPop::~SongSelectPop() {
	delete blackBox;
	delete title;
	delete message;
	for (int i = 0; i < 2; i++)
		delete button[i];
}