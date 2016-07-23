#include "Draw.h"

//�F�w��
void Color::Set(char *color) {
	if(!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //���F
	else if(!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //�F
}

//�F�擾
int Color::Get() {
	return c;
}

int Color::White() {
	return GetColor(255, 255, 255); //���F
}

int Color::Blue() {
	return GetColor(127, 210, 234); //�F
}

//�t�H���g�w��
void Font::Set(int p) {
	ID = CreateFontToHandle("M+ 1c", p / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
}

//�t�H���g�擾
int Font::Get() {
	return ID;
}

//�|�W�V�����w��(�E��/������/����)
void ViewPos::Init(int a, int b, int pos = 0, int len = 0) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
	switch (pos) {
	case 1:
		x = x - len / 2;;
		break;
	case 2:
		x = x - len;
		break;
	}
}

//x���W�擾
int ViewPos::GetX() {
	return x;
}

//y���W�擾
int ViewPos::GetY() {
	return y;
}

//�e�L�X�g������
void MyDrawText::Init(char *s, int a, int b, int pos, int point) {
	str = s;
	font.Set(point);
	color.Set("White");
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	viewPos.Init(a, b, pos, strLen);
}

//�e�L�X�g�\��
void MyDrawText::Draw() {
	DrawStringToHandle(viewPos.GetX(), viewPos.GetY(), str, color.Get(), font.Get()); //�����\��
}

//�e�L�X�g�̕��擾
int MyDrawText::GetWidth() {
	return strLen;
}

//��������
void MyDrawLine::Init(int a, int b, int pos, int length, int width) {
	color.Set("White");
	viewPos.Init(a, b, pos, length);
	w = width / SIZE_RATE;
	len = length;
}

//���\��
void MyDrawLine::Draw() {
	DrawLine(viewPos.GetX(), viewPos.GetY(), viewPos.GetX() + len, viewPos.GetY(), color.Get(), 2);
}

//�~������
void MyDrawCircle::Init(int a, int b, int radius) {
	viewPos.Init(a, b);
	color.Set("Blue");
	r = radius / SIZE_RATE;
}

//�~�\��
void  MyDrawCircle::Draw() {
	DrawCircleAA(viewPos.GetX(), viewPos.GetY(), r, 100, color.Get(), TRUE);
}

//�摜������
void MyDrawGraph::Init(int a, int b, char *filename) {
	viewPos.Init(a, b);
	handle = LoadGraph(filename); // �摜�̃��[�h
}

//�摜�\��
void MyDrawGraph::Draw() {
	DrawRotaGraph(viewPos.GetX(), viewPos.GetY(), 1.0 / SIZE_RATE, 0, handle, TRUE, FALSE); //�`��
}