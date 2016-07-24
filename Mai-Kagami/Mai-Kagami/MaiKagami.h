#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "DxLib.h"
#include "Top.h"
#include "Loading.h"
#include "SongSelect.h"

class MaiKagami
{
public:
	MaiKagami(); //�R���X�g���N�^
	void Update();
	void View(); //�\��
private:
	int scene; //�V�[��
	Top *top; //�g�b�v���
	Loading *loading; //���[�f�B���O���
	SongSelect *songSelect; //�ȑI�����
};

#endif