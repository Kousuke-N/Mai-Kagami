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

#define BACK_TOP -2
#define BACK -1
#define MAIN 0
#define MODE 1
#define OPTION 2

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
	void Update(Touch *touch);
	~SongSelectCover();
private:
	int n;
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
	int Update(Touch *touch);
	void View();
	~SongSelectPop();
private:
	MyDrawBox *myDrawBox;
	MyDrawText *title;
	MyDrawText *message;
	Button *button[2];
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
	Touch *touch; //�T�C�h�^�b�`�p�l��
	int scene;
	int loadFlag;
	void Load();
	void Delete();
};

#endif