#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "TopMain.h"
#include "SongSelectMain.h"
#include "Songs.h"
#include "ThroughMain.h"
#include "Touch.h"
#include "DxLib.h"

class MaiKagami
{
public:
	MaiKagami(); //�R���X�g���N�^
	void Update();
	void View(); //�\��
private:
	int scene; //�V�[��
	Font *font; //�t�H���g
	Top *top; //�g�b�v���
	SongSelect *songSelect; //�ȑI�����
	ThroughMain *throughMain; //�ʂ����K
	Songs *songs; //�Ȉꗗ
	Touch *touch;
};

#endif