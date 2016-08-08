#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "DrawObject.h"
#include "Drawtext.h"
#include "Button.h"
#include "Touch.h"
#include "Font.h"

//�ȑI����ʃ{�^���֌W
class SongSelectButton {
public:
	SongSelectButton(Font *font); //������
	void View(); //�\��
	~SongSelectButton();
private:
	Button *button[4];
};

//�|�b�v�A�b�v�֌W
class SongSelectPop {
public:
	SongSelectPop(Font *font);
	void View();
	~SongSelectPop();
private:
	BlackBox *blackBox;
	MyDrawText *title;
	MyDrawText *message;
	Button *button[2];
};

#endif