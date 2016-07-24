#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Nfc.h"

//NFC�^�b�`���b�Z�[�W�֌W
class TopTouchMessage {
public:
	void Init();
	void Update(); //�v�Z
	void View(); //�\��
private:
	MyDrawText myDrawText;
	int alpha; //�����x
};

//NFC�^�b�`�{�^���֌W
class TopTouchButton {
public:
	void Init();
	void View(); //�\��
private:
	MyDrawCircle myDrawCircle;
	MyDrawText myDrawText;
};

//�g�b�v��ʊ֌W
class Top { 
public:
	void Load();
	int Update(); //�v�Z
	void View(); //�\��
private:
	MyDrawGraph myDrawGraph; //�g�b�v���S
	TopTouchMessage topTouchMessage; //NFC�^�b�`���b�Z�[�W
	TopTouchButton topTouchButton; //NFC�^�b�`�{�^��
	Nfc nfc; //NFC�Ď�
};

#endif