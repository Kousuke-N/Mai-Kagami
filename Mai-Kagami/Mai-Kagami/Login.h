#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

#include "Main.h"
#include "DxLib.h"
#include "Draw.h"

//���O�C�����b�Z�[�W
class LoginMessage {
public:
	void Init();
	void View(); //�\��
private:
	MyDrawText myDrawText;
};

//���O�C���A�j���[�V����
class LoginAnimation {
public:
	void Init();
	void Update();
	void View(); //�\��
private:
	MyDrawCircle myDrawCircle[3];
	int alpha[3]; //�����x
	int x, y, r; //�\���ʒu�A���a
};

//���O�C����ʊ֌W
class Login {
public:
	void Load(); //���[�h
	void Update(); //�v�Z
	void View(); //�\��
private:
	LoginMessage loginMessage; //���O�C�����b�Z�[�W
	LoginAnimation loginAnimation; //���O�C���A�j���[�V����
};

#endif