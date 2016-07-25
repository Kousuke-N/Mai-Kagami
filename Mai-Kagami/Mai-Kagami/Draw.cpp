#include "Draw.h"

//�F�w��
Color::Color(char *color) {
	if(!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //���F
	else if(!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //�F
	else if(!strcmp(color, "Black"))
		c = GetColor(0, 0, 0); //�F
}

//�F�擾
int Color::Get() {
	return c;
}

//�t�H���g�w��
Font::Font(int p) {
	ID = CreateFontToHandle("M+ 1c", p / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
}

//�t�H���g�擾
int Font::Get() {
	return ID;
}

//�t�H���g�f�X�g���N�^
Font::~Font() {
	DeleteFontToHandle(ID); //�t�H���g�f�[�^���폜
}

//�|�W�V�����w��(�E��/������/����)
ViewPos::ViewPos(float a, float b, int pos, float len) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
	switch (pos) {
	case 1:
		x = x - len / 2;
		break;
	case 2:
		x = x - len;
		break;
	}
}

void ViewPos::ChangePos(float a, float b) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
}

//x���W�擾
float ViewPos::GetX() {
	return x;
}

//y���W�擾
float ViewPos::GetY() {
	return y;
}

//�e�L�X�g������
MyDrawText::MyDrawText(char *s, int a, int b, int pos, int point, char *colorName) {
	str = s; x = a; y = b; p = pos;
	font = new Font(point);
	color = new Color(colorName);
}

//�e�L�X�g�\��
void MyDrawText::Draw() {
	ViewPos viewPos(x, y, p, GetWidth() / SIZE_RATE);
	DrawStringToHandle(viewPos.GetX(), viewPos.GetY(), str, color->Get(), font->Get()); //�����\��
}

//�e�L�X�g�̕��擾
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(str, (int)strlen(str), font->Get()) * SIZE_RATE;
}

//�e�L�X�g�f�X�g���N�^
MyDrawText::~MyDrawText() {
	delete font;
	delete color;
}

//��������
MyDrawLine::MyDrawLine(int a, int b, int pos, int length, int width) {
	color = new Color("White");
	len = length / SIZE_RATE;
	viewPos = new ViewPos(a, b, pos, len);
	w = width / SIZE_RATE;
}

//���\��
void MyDrawLine::Draw() {
	DrawLine(viewPos->GetX(), viewPos->GetY(), viewPos->GetX() + len, viewPos->GetY(), color->Get(), 2);
}

//���f�X�g���N�^
MyDrawLine::~MyDrawLine() {
	delete color;
	delete viewPos;
}

//�~������
MyDrawCircle::MyDrawCircle(int a, int b, int radius) {
	viewPos = new ViewPos(a, b);
	color = new Color("Blue");
	r = radius / SIZE_RATE;
}

//�~�\��
void  MyDrawCircle::Draw() {
	DrawCircleAA(viewPos->GetX(), viewPos->GetY(), r, 100, color->Get(), TRUE);
}

MyDrawCircle::~MyDrawCircle() {
	delete color;
	delete viewPos;
}

//�����O������
MyDrawRing::MyDrawRing(int a, int b, int radius, float width, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//�����O�\��
void  MyDrawRing::Draw() {
	DrawCircleAA(viewPos->GetX(), viewPos->GetY(), r, 100, color->Get(), FALSE, w);
}

MyDrawRing::~MyDrawRing() {
	delete color;
	delete viewPos;
}

//�O�p�`������
MyDrawTriangle::MyDrawTriangle(int a, int b, int width, int direction) {
	viewPos = new ViewPos(a, b);
	color = new Color("Blue");
	w = width / SIZE_RATE;
	d = direction;
}

//�O�p�`�\��
void  MyDrawTriangle::Draw() {
	float x1 = viewPos->GetX();			float y1 = viewPos->GetY();
	float x2 = viewPos->GetX() - w / 2;	float y2 = viewPos->GetY();
	float x3 = viewPos->GetX() + w / 2;	float y3 = viewPos->GetY();
	float a = w * sqrt(3) / 4;

	if (d == 0) {
		y1 -= a; y2 += a; y3 += a;
	}
	else {
		y1 += a; y2 -= a; y3 -= a;
	}

	DrawTriangleAA(x1, y1, x2, y2, x3, y3, color->Get(), TRUE);
}

MyDrawTriangle::~MyDrawTriangle() {
	delete color;
	delete viewPos;
}

//�l�p�`������
MyDrawBox::MyDrawBox(int a, int b, int width, int height, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
}

//�l�p�`�\��
void  MyDrawBox::Draw() {
	float x1 = viewPos->GetX() - w / 2 + 1;
	float y1 = viewPos->GetY() - h / 2 + 1;
	float x2 = viewPos->GetX() + w / 2;
	float y2 = viewPos->GetY() + h / 2;

	DrawBoxAA(x1, y1, x2, y2, color->Get(), TRUE);
}

MyDrawBox::~MyDrawBox() {
	delete color;
	delete viewPos;
}

//�摜������
MyDrawGraph::MyDrawGraph(float a, float b, char *filename, double ExRate) {
	viewPos = new ViewPos(a, b);
	handle = LoadGraph(filename); // �摜�̃��[�h
	ex = ExRate;
}

//�摜�\��
void MyDrawGraph::Draw() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(viewPos->GetX(), viewPos->GetY(), ex / SIZE_RATE, 0, handle, TRUE, FALSE); //�`��
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

void MyDrawGraph::ChangePos(float a, float b) {
	viewPos->ChangePos(a, b);
}

void MyDrawGraph::ChangeEx(double ExRate) {
	ex = ExRate;
}

MyDrawGraph::~MyDrawGraph() {
	delete viewPos;
	DeleteGraph(handle);
}