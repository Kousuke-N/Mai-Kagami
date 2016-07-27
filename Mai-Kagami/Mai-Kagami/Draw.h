#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include <string>
#include "DxLib.h"
#include "Main.h"
#include "Font.h"

//�F�֌W
class Color {
public:
	Color(char *color);
	int Get();
private:
	int c;
};

//�\���ʒu�֌W
class ViewPos {
public :
	ViewPos(float a, float b, int pos = 0, float len = 0);
	void ChangePos(float a, float b);
	void ChangeLenth( float len);
	float GetX();
	float GetY();
private:
	float x, y;
	float xx, yy;
	int p;
};

//�e�L�X�g�֌W
class MyDrawText {
public:
	MyDrawText(Font *font, char *s, int a, int b, int pos, int point, char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void Draw(); //�`��
	void ChangeText(char *s);
	int GetWidth(); //���擾
	~MyDrawText();
private:
	int f;
	ViewPos *viewPos;
	Color *color;
	std::string str; //����
};

//���֌W
class MyDrawLine {
public:
	MyDrawLine(int a, int b, int pos, int length, int width); // pos=����:0 / ������:1 / �E��:2
	void Draw();
	~MyDrawLine();
private:
	ViewPos *viewPos;
	Color *color;
	int len; //������̒���
	int w;
};

//�~�֌W
class MyDrawCircle {
public:
	MyDrawCircle(int a, int b, int radius, char *colorName = "Blue");
	MyDrawCircle(int a, int b, int radius, float width, char *colorName = "Blue");
	void Draw();
	~MyDrawCircle();
private:
	ViewPos *viewPos;
	Color *color;
	int r;
	float w;
};

//���O�p�`�֌W
class MyDrawTriangle {
public:
	MyDrawTriangle(int a, int b, int width, int direction, char *colorName = "Blue");
	void Draw();
	~MyDrawTriangle();
private:
	ViewPos *viewPos;
	Color *color;
	int d;
	float w;
};

//�l�p�`�֌W
class MyDrawBox {
public:
	MyDrawBox(int a, int b, int width, int height, char *colorName = "White");
	MyDrawBox(int a, int b, int width, int height, float line, char *colorName = "Blue");
	void Draw();
	~MyDrawBox();
private:
	ViewPos *viewPos;
	Color *color;
	int w, h;
	float l;
};

//�摜�֌W
class MyDrawGraph {
public:
	MyDrawGraph(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	~MyDrawGraph();
private:
	ViewPos *viewPos;
	int handle;
	double ex;
};

//����֌W
class MyDrawMovie {
public:
	MyDrawMovie(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	void ChangeSpeed(double speed);
	~MyDrawMovie();
private:
	ViewPos *viewPos;
	int handle; //����̃n���h��
	double ex; //����̃T�C�Y
};

#endif