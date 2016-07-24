#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Nfc.h"

//NFC�^�b�`���b�Z�[�W�֌W
class TopTouchMessage {
public:
	TopTouchMessage();
	void Update(); //�v�Z
	void View(); //�\��
	~TopTouchMessage();
private:
	MyDrawText *myDrawText;
	int alpha, t; //�����x, ����
};

//NFC�^�b�`�{�^���֌W
class TopTouchButton {
public:
	TopTouchButton();
	void View(); //�\��
	~TopTouchButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawText *myDrawText;
};

//�g�b�v��ʊ֌W
class Top { 
public:
	int Update(); //�v�Z
	void View(); //�\��
private:
	MyDrawGraph *myDrawGraph; //�g�b�v���S
	TopTouchMessage *topTouchMessage; //NFC�^�b�`���b�Z�[�W
	TopTouchButton *topTouchButton; //NFC�^�b�`�{�^��
	Nfc nfc; //NFC�Ď�
	int loadFlag = 0;
	boolean Load();
};

#endif