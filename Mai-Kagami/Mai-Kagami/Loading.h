#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

#include "Main.h"
#include "DxLib.h"
#include "Draw.h"

//���O�C����ʊ֌W
class Loading {
public:
	Loading(); //���[�h
	void Update(); //�v�Z
	void View(); //�\��
	~Loading();
private:
	MyDrawText *myDrawText;
};

#endif