#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

#include "Main.h"
#include "DxLib.h"
#include "Draw.h"

//���O�C�����b�Z�[�W
class LoginMessage {
public:
	LoginMessage();
	void View(); //�\��
private:
	Font font;
	char *str; //�\��������
	int x, y; //�\���ʒu
};

//���O�C���A�j���[�V����
class LoginAnimation {
public:
	LoginAnimation();
	void Update();
	void View(); //�\��
private:
	int alpha[3]; //�����x
	int x, y, r; //�\���ʒu�A���a
};

//���O�C����ʊ֌W
class Login {
public:
	void Update(); //�v�Z
	void View(); //�\��
private:
	LoginMessage loginMessage; //���O�C�����b�Z�[�W
	LoginAnimation loginAnimation; //���O�C���A�j���[�V����
};

#endif