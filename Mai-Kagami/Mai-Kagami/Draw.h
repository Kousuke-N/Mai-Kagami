#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"

class Color {
public:
	int White(); //���F
	int Blue(); //�F
private:
};

class Font {
public:
	void Set(int p); //�|�C���g���Z�b�g
	int Get(); //�t�H���gID���o��
private:
	int ID; //�t�H���gID
};

class ViewPos {
public :
	void Init(int a, int b);
	void Init(int a, int b, int pos, int len);
	int GetX();
	int GetY();
private:
	int x, y;
};

class MyDrawText {
public:
	void Init(char *s, int a, int b, int pos, int point); // pos=����:0 / ������:1 / �E��:2
	void Draw();
private:
	ViewPos viewPos;
	Font font;
	Color color;
	char *str; //����
	int strLen; //������̒���
};

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

class MyDrawCircle {
public:
	void Init(int a, int b, int radius);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
};

#endif