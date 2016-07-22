#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "Draw.h"

//�ȑI����ʃ^�C�g��
class SongSelectTitle {
public:
	void Init(); //������
	void View(); //�\��
private:
	MyDrawText myDrawText;
	MyDrawLine myDrawLine;
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
	int loadFlag;
};

#endif