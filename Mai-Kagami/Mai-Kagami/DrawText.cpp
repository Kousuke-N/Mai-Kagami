#include "DrawText.h"

//�e�L�X�g������
MyDrawText::MyDrawText(Font *font, char *s, int a, int b, int pos, int point, char *colorName) {
	str = s;
	f = font->Get(point);
	color = new Color(colorName);
	viewPos = new ViewPos(a, b, pos, GetWidth() / SIZE_RATE);
}

//�e�L�X�g�\��
void MyDrawText::Draw() {
	DrawStringToHandle(viewPos->GetX(), viewPos->GetY(), str.c_str(), color->Get(), f); //�����\��
}

//�e�L�X�g�ύX
void MyDrawText::ChangeText(char *s) {
	str = s;
	viewPos->ChangeLenth(GetWidth() / SIZE_RATE);
}

//�e�L�X�g�̕��擾
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(str.c_str(), (int)strlen(str.c_str()), f) * SIZE_RATE;
}

//�e�L�X�g�f�X�g���N�^
MyDrawText::~MyDrawText() {
	delete viewPos;
	delete color;
}