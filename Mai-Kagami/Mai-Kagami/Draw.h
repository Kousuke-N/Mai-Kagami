#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include "DxLib.h"
#include "Main.h"

//�F�֌W
class Color {
public:
	void Set(char *color);
	int Get();
private:
	int c;
};

//�t�H���g�֌W
class Font {
public:
	void Set(int p); //�|�C���g���Z�b�g
	int Get(); //�t�H���gID���o��
private:
	int ID; //�t�H���gID
};

//�\���ʒu�֌W
class ViewPos {
public :
	void Init(float a, float b, int pos = 0, float len = 0);
	float GetX();
	float GetY();
private:
	float x, y;
};

//�e�L�X�g�֌W
class MyDrawText {
public:
	void Init(char *s, int a, int b, int pos, int point); // pos=����:0 / ������:1 / �E��:2
	void Draw(); //�`��
	int GetWidth(); //���擾
private:
	ViewPos viewPos;
	Font font;
	Color color;
	char *str; //����
	int strLen; //������̒���
};

//���֌W
class MyDrawLine {
public:
	void Init(int a, int b, int pos, int length, int width); // pos=����:0 / ������:1 / �E��:2
	void Draw();
private:
	ViewPos viewPos;
	Font font;
	Color color;
	int len; //������̒���
	int w;
};

//�~�֌W
class MyDrawCircle {
public:
	void Init(int a, int b, int radius);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
};

//�����O�i�h�[�i�c�^�j�֌W
class MyDrawRing {
public:
	void Init(int a, int b, int radius, float width);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
	float w;
};

//���O�p�`�֌W
class MyDrawTriangle {
public:
	void Init(int a, int b, int width, int direction);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int d;
	float w;
};

//�l�p�`�֌W
class MyDrawBox {
public:
	void Init(int a, int b, int width, int height);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int w, h;
};

//�摜�֌W
class MyDrawGraph {
public:
	void Init(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
private:
	ViewPos viewPos;
	int handle;
	double ex;
};

#endif