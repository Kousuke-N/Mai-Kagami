#ifndef __FONT_H_INCLUDED__
#define __FONT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"

#define FONT_NUM 7

//�t�H���g�֌W
class Font {
public:
	Font(); //�|�C���g���Z�b�g
	int Get(int point); //�t�H���gID���o��
	~Font();
private:
	int ID[FONT_NUM]; //�t�H���gID
};

#endif