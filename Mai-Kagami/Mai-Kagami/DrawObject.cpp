#include "DrawObject.h"

//��������
MyDrawLine::MyDrawLine(int a, int b, int pos, int length, int width) {
	color = new Color("White");
	len = length / SIZE_RATE;
	viewPos = new ViewPos(a, b, pos, len);
	w = width / SIZE_RATE;
}

//���\��
void MyDrawLine::Draw() {
	DrawLine(viewPos->GetX(), viewPos->GetY(), viewPos->GetX() + len, viewPos->GetY(), color->Get(), w);
}

//���f�X�g���N�^
MyDrawLine::~MyDrawLine() {
	delete color;
	delete viewPos;
}

//�~������
MyDrawCircle::MyDrawCircle(int a, int b, int radius, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	r = radius / SIZE_RATE;
	w = 0;
}

//�~������2
MyDrawCircle::MyDrawCircle(int a, int b, int radius, float width, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//�~�\��
void  MyDrawCircle::Draw() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(viewPos->GetX(), viewPos->GetY(), r, 100, color->Get(), flag, w);
}

MyDrawCircle::~MyDrawCircle() {
	delete color;
	delete viewPos;
}

//�O�p�`������
MyDrawTriangle::MyDrawTriangle(int a, int b, int width, int direction, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	w = width / SIZE_RATE;
	d = direction;
}

//�O�p�`�\��
void  MyDrawTriangle::Draw() {
	float x1 = viewPos->GetX();	float y1 = viewPos->GetY();
	float x2 = viewPos->GetX();	float y2 = viewPos->GetY();
	float x3 = viewPos->GetX();	float y3 = viewPos->GetY();
	float a = w * sqrt(3) / 4;

	switch (d)
	{
	case 0:
		x2 -= w / 2; x3 += w / 2;
		y1 -= a; y2 += a; y3 += a;
		break;
	case 1:
		x2 -= w / 2; x3 += w / 2;
		y1 += a; y2 -= a; y3 -= a;
		break;
	case 2:
		y2 -= w / 2; y3 += w / 2;
		x1 += a; x2 -= a; x3 -= a;
		break;
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
	l = 0;
}

//�l�p�`������2
MyDrawBox::MyDrawBox(int a, int b, int width, int height, float line, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = line / SIZE_RATE;
}

//�l�p�`�\��
void  MyDrawBox::Draw() {
	boolean flag = TRUE;
	if (l != 0)
		flag = FALSE;
	float x1 = viewPos->GetX() - w / 2 + 1;
	float y1 = viewPos->GetY() - h / 2 + 1;
	float x2 = viewPos->GetX() + w / 2;
	float y2 = viewPos->GetY() + h / 2;

	DrawBoxAA(x1, y1, x2, y2, color->Get(), flag, l);
}

MyDrawBox::~MyDrawBox() {
	delete color;
	delete viewPos;
}