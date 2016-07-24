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

//�ȑI����ʃ^�C�g��
class SongSelectTitle {
public:
	SongSelectTitle(); //������
	void View(); //�\��
	~SongSelectTitle();
private:
	MyDrawText *myDrawText;
	MyDrawLine *myDrawLine;
};

//�ȑI����ʃJ�o�[�֌W
class SongSelectCover {
public:
	SongSelectCover(); //������
	void View(); //�\��
	~SongSelectCover();
private:
	MyDrawText *songTitle;
	MyDrawText *songArtist;
	MyDrawText *songLast[2];
	MyDrawLine *myDrawLine;
	MyDrawGraph *myDrawGraph; //�J�o�[�摜
	MyDrawGraph *songCover[6]; //�J�o�[�摜
	MyDrawGraph *grad[2]; //�J�o�[�摜
	MyDrawGraph *box; //�J�o�[�摜
	MyDrawBox *myDrawBox;
};

//�ȑI����ʃ{�^���֌W
class SongSelectButton {
public:
	SongSelectButton(); //������
	void View(); //�\��
	~SongSelectButton();
private:
	Button *button[4];
};

//�ȑI����ʊ֌W
class SongSelect {
public:
	SongSelect();
	int Update();
	void View(Loading *loading);
private:
	SongSelectTitle *songSelectTitle; //�ȑI����ʃ^�C�g��
	SongSelectCover *songSelectCover; //�I�𒆂̋�
	SongSelectButton *songSelectButton; //�{�^���֌W
	Touch touch; //�T�C�h�^�b�`�p�l��
	int loadFlag;
	boolean Load();
	void Delete();
};

#endif