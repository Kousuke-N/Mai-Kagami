#include "DrawText.h"

//�e�L�X�g������
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName)
	: Color(colorName) {
	s = str; //������
	p = pos; //�ʒu���
	f = font->Get(point); //�t�H���g���
	MyDrawText::x = x;
	MyDrawText::y = y;
	CalcPos();
}

//�e�L�X�g�\��
void MyDrawText::View() {
	DrawStringToHandle(GetX(), GetY(), s.c_str(), Color::Get(), f); //�����\��
}

//�e�L�X�g�ύX
void MyDrawText::ChangeText(char *str) {
	s = str;
	CalcPos();
}

//�e�L�X�g�̕��擾
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(s.c_str(), (int)strlen(s.c_str()), f) * SIZE_RATE;
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

	int line = 1; //�s��
	for (int i = 0; i < strlen(s.c_str()); i++) {
		if (s[i] == '\n')
			line++;
	}

	ChangePos(a, b - p * (1 + 1 / 3) * line / 2);
}