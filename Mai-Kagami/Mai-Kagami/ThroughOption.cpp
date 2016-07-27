#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font) {
	button[0] = new Button(font, "UP", 1, 0);
	button[1] = new Button(font, "DOWN", 2, 1);
	button[2] = new Button(font, "�X�^�[�g!", 0, 2);
	button[3] = new Button(font, "�߂�", 3, 4);
	speed[0] = new MyDrawText(font, "�X�s�[�h", WIDTH * 0.72, HEIGHT * 0.5165, 0, 30);
	speed[1] = new MyDrawText(font, "�~1.0", WIDTH * 0.86, HEIGHT * 0.5165, 0, 30, "Yellow");
}


//���[�h�I���{�^���\��
void ThroughOptionButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->Draw();
	for (int i = 0; i < 2; i++)
		speed[i]->Draw();
}

//���[�h�I���폜
ThroughOptionButton::~ThroughOptionButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
	for (int i = 0; i < 2; i++)
		delete speed[i];
}