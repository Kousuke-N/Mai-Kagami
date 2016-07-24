#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include "DxLib.h"
#include "Main.h"

//�F�֌W
class Color {
public:
	Color(char *color);
	int Get();
private:
	int c;
};

//�t�H���g�֌W
class Font {
public:
	Font(int p); //�|�C���g���Z�b�g
	int Get(); //�t�H���gID���o��
	~Font();
private:
	int ID; //�t�H���gID
};

//�\���ʒu�֌W
class ViewPos {
public :
	ViewPos(float a, float b, int pos = 0, float len = 0);
	float GetX();
	float GetY();
private:
	float x, y;
};

//�e�L�X�g�֌W
class MyDrawText {
public:
	MyDrawText(char *s, int a, int b, int pos, int point, char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void Draw(); //�`��
	int GetWidth(); //���擾
	~MyDrawText();
private:
	Font *font;
	Color *color;
	char *str; //����
	int x, y, p;
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
	MyDrawCircle(int a, int b, int radius);
	void Draw();
	~MyDrawCircle();
private:
	ViewPos *viewPos;
	Color *color;
	int r;
};

//�����O�i�h�[�i�c�^�j�֌W
class MyDrawRing {
public:
	MyDrawRing(int a, int b, int radius, float width, char *colorName = "Blue");
	void Draw();
	~MyDrawRing();
private:
	ViewPos *viewPos;
	Color *color;
	int r;
	float w;
};

//���O�p�`�֌W
class MyDrawTriangle {
public:
	MyDrawTriangle(int a, int b, int width, int direction);
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
	void Draw();
	~MyDrawBox();
private:
	ViewPos *viewPos;
	Color *color;
	int w, h;
};

//�摜�֌W
class MyDrawGraph {
public:
	MyDrawGraph(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	~MyDrawGraph();
private:
	ViewPos *viewPos;
	int handle;
	double ex;
};

#endif