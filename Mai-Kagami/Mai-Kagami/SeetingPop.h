#ifndef __SETTINGPOP_H_INCLUDED__
#define __SETTINGPOP_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"
#include "DrawText.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"

//�|�b�v�A�b�v�p�l�p�`�i���F�������S��ʁj
class BlackBox : public MyDrawBox {
public:
	BlackBox();
	void View();
private:
};

//�X�s�[�h�I�v�V�����\��
class SpeedOption {
public:
	SpeedOption(Font *font, Songs *songs);
	void Update();
	void View();
	~SpeedOption();
private:
	Button *button[2];
	MyDrawText *speed[2];
	Songs *songs;
};

//�X�s�[�h�I�v�V�����|�b�v�A�b�v
class SpeedPop : public SpeedOption {
public:
	SpeedPop(Font *font, Songs *songs);
	void Update();
	void View();
	~SpeedPop();
private:
	BlackBox *blackBox;
	Button *button;
};

#endif