#include "Loading.h"

//���O�C����ʃ��[�h
Loading::Loading() {
	char *str = "���[�f�B���O��"; //�\��������
	myDrawText = new MyDrawText(str, WIDTH / 2, HEIGHT * 0.46, 1, 50);
}

//���O�C����ʌv�Z
void Loading::Update() {
}

//���O�C����ʕ\��
void Loading::View() {
	myDrawText->Draw();
}

Loading::~Loading() {
	delete myDrawText;
}