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

#endif