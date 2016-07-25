#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Common.h"
#include "Touch.h"
#include "Loading.h"
#include "Song.h"
#include "Font.h"

//�ȑI����ʃ^�C�g��
class SongSelectTitle {
public:
	SongSelectTitle(Font *font); //������
	void View(); //�\��
	~SongSelectTitle();
private:
	MyDrawText *myDrawText;
	MyDrawLine *myDrawLine;
};

//�ȑI����ʃJ�o�[�֌W
class SongSelectCover {
public:
	SongSelectCover(Font *font); //������
	void View(); //�\��
	void Update(int num = -1);
	~SongSelectCover();
private:
	Song *song[256];
	MyDrawGraph *grad[2]; //�J�o�[�摜
	MyDrawGraph *box; //�J�o�[�摜
	MyDrawBox *myDrawBox;
};

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
	void Update(int num);
	void View();
	boolean Flag();
	~SongSelectPop();
private:
	MyDrawBox *myDrawBox;
	MyDrawText *title;
	MyDrawText *message;
	MyDrawText *buttonMessage[2];
	MyDrawRing *buttonRing[2];
	boolean flag;
};

//�ȑI����ʊ֌W
class SongSelect {
public:
	SongSelect(Font *font);
	int Update();
	void View(Loading *loading);
private:
	Font *f;
	SongSelectTitle *songSelectTitle; //�ȑI����ʃ^�C�g��
	SongSelectCover *songSelectCover; //�I�𒆂̋�
	SongSelectButton *songSelectButton; //�{�^���֌W
	SongSelectPop *songSelectPop; //�I���p�|�b�v�A�b�v
	Touch touch; //�T�C�h�^�b�`�p�l��
	int loadFlag;
	boolean Load();
	void Delete();
};

#endif