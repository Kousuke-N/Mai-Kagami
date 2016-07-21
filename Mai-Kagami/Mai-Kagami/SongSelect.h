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
	int logo; //�摜ID
	char *str; //����
	int x, y; //�\���ʒu
	Font font; //�t�H���g
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