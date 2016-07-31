#ifndef __DRAWOBJECT_H_INCLUDED__
#define __DRAWOBJECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"

//�~�֌W
class MyDrawCircle : public Draw, public Color{
public:
	MyDrawCircle(const float x, const float y, const float radius, const char *colorName = "Blue"); //�~�������i�h��Ԃ�����j
	MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName = "Blue"); //�~�������i�h��Ԃ��Ȃ��j
	void View();
private:
	float r, w; //���a�A���̑���
};

//���O�p�`�֌W
class MyDrawTriangle : public Draw, public Color {
public:
	MyDrawTriangle(const float x, const float y, const float width, const int direction, const char *colorName = "Blue");
	void View(); //�\��
private:
	int d;
	float w;
};

//�l�p�`�֌W
class MyDrawBox : public Draw, public Color {
public:
	MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName = "White"); //�l�p�`�������i�h��Ԃ�����j
	MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName = "Blue"); //�l�p�`�������i�h��Ԃ��Ȃ��j
	void View();
	void ChangeSize(const float width, const float height);
private:
	float w, h, l; //���A�����A���̑���
};

class MyDrawBar : public MyDrawBox {
public:
	MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName = "White"); //�l�p�`�������i�h��Ԃ�����j
	void ChangeSize(const float width, const float height);
private:
	float x, y; //���W
};

#endif