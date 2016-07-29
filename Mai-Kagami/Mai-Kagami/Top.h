#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawGraph.h"
#include "DrawObject.h"
#include "Nfc.h"
#include "Font.h"

class TopLogo : public MyDrawGraph {
public:
	TopLogo( const float y);
};

//NFC�^�b�`���b�Z�[�W�֌W
class TopTouchMessage : public MyDrawText {
public:
	TopTouchMessage(Font *font, const float y);
	void Init(); //������
	void Update(); //�v�Z
	void View(); //�\��
private:
	int alpha, t; //�����x, ����
};

//NFC�^�b�`�{�^���֌W
class TopTouchButton : public MyDrawText, public MyDrawCircle {
public:
	TopTouchButton(Font *font, const float r);
	void View(); //�\��
};

//�g�b�v��ʊ֌W
class Top { 
public:
	Top(Font *font);
	int Update(); //�v�Z
	void View(); //�\��
	~Top();
private:
	Font *f;
	TopLogo *topLogo; //�g�b�v���S
	TopTouchMessage *topTouchMessage; //NFC�^�b�`���b�Z�[�W
	TopTouchButton *topTouchButton; //NFC�^�b�`�{�^��
	Nfc nfc; //NFC�Ď�
	int loadFlag;
	void Load();
	void Delete();
};

#endif