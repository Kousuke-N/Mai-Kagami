#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Common.h"

//�ȑI����ʃ^�C�g��
class SongSelectTitle {
public:
	void Init(); //������
	void View(); //�\��
private:
	MyDrawText myDrawText;
	MyDrawLine myDrawLine;
};

//�ȑI����ʃJ�o�[�֌W
class SongSelectCover {
public:
	void Init(); //������
	void View(); //�\��
private:
	MyDrawText songTitle;
	MyDrawText songArtist;
	MyDrawText songLast[2];
	MyDrawLine myDrawLine;
	MyDrawGraph myDrawGraph; //�J�o�[�摜
	MyDrawGraph songCover[6]; //�J�o�[�摜
	MyDrawGraph grad[2]; //�J�o�[�摜
	MyDrawGraph box; //�J�o�[�摜
	MyDrawBox myDrawBox;
};

//�ȑI����ʃ{�^���֌W
class SongSelectButton {
public:
	void Init(); //������
	void View(); //�\��
private:
	Button button[4];
};

//�ȑI����ʊ֌W
class SongSelect {
public:
	int Load();
	void Update();
	void View();
private:
	void LoadThread(); //���[�h�X���b�h
	SongSelectTitle songSelectTitle; //�ȑI����ʃ^�C�g��
	SongSelectCover songSelectCover; //�I�𒆂̋�
	SongSelectButton songSelectButton; //�{�^���֌W
	int loadFlag;
};

#endif