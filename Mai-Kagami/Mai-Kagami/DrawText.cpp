#include "DrawText.h"

//�e�L�X�g������
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, char *colorName)
	: Draw(x, y), Color(colorName) {
	s = str; //������
	p = pos; //�ʒu���
	f = font->Get(point); //�t�H���g���
}

//�e�L�X�g�\��
void MyDrawText::View() {
	float x = GetX();
	float y = GetY();
	switch (p) {
	case 1:
		x -= GetWidth() / 2;
		break;
	case 2:
		x -= GetWidth();
		break;
	}
	DrawStringToHandle(x, y, s.c_str(), Color::Get(), f); //�����\��
}

//�e�L�X�g�ύX
void MyDrawText::ChangeText(char *str) {
	s = str;
}

//�e�L�X�g�̕��擾
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(s.c_str(), (int)strlen(s.c_str()), f);
}