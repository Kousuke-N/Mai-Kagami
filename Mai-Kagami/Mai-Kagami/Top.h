#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawGraph.h"
#include "DrawObject.h"
#include "Font.h"

//�g�b�v���S
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
class TopTouchButton : public Draw{
public:
	TopTouchButton(Font *font);
	void View(); //�\��
	~TopTouchButton();
private:
	MyDrawText *text;
	MyDrawCircle *circle;
};

#endif