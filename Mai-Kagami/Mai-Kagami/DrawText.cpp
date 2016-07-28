#include "DrawText.h"

//�e�L�X�g������
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName)
	: Color(colorName) {
	s = str; //������
	p = pos; //�ʒu���
	f = font->Get(point); //�t�H���g���
	MyDrawText::x = x;
	MyDrawText::y = y;
	MyDrawText::point = point;
	CalcPos();
}

//�e�L�X�g�\��
void MyDrawText::View() {
	DrawStringFToHandle(GetX(), GetY(), s.c_str(), Color::Get(), f); //�����\��
}

//�e�L�X�g�ύX
void MyDrawText::ChangeText(char *str) {
	s = str;
	CalcPos();
}

//�e�L�X�g�̏c�擾
float MyDrawText::GetHeight() {
	int line = 1; //�s��
	for (int i = 0; i < strlen(s.c_str()); i++) {
		if (s.c_str()[i] == '\n')
			line++;
	}

	return (float)point * (1 + 1 / 3) * line;
}

//�e�L�X�g�̕��擾
float MyDrawText::GetWidth() {
	return 	(float)GetDrawStringWidthToHandle(s.c_str(), (int)strlen(s.c_str()), f) * SIZE_RATE;
}

//�e�L�X�g�̍��W�v�Z
void MyDrawText::CalcPos() {
	float a = x;
	float b = y;
	switch (p) {
	case 1:
		a -= GetWidth() / 2;
		break;
	case 2:
		a -= GetWidth();
		break;
	}

	ChangePos(a, b - GetHeight() / 2);
}

MyDrawTextLine::MyDrawTextLine(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName)
	: MyDrawText(font, str, x, y, pos, point, colorName)  {
	w = lineWidth / SIZE_RATE;
	x1 = (x - lineLength / 2) / SIZE_RATE;
	x2 = (x + lineLength / 2) / SIZE_RATE;
	y1 = y2 = (y + MyDrawText::GetHeight() * 0.9) / SIZE_RATE;
}

void MyDrawTextLine::View() {
	MyDrawText::View();
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}