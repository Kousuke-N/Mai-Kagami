#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "DxLib.h"
#include "Top.h"
//#include "Login.h"
//#include "SongSelect.h"

class MaiKagami
{
public:
	MaiKagami(); //�R���X�g���N�^
	void View(); //�\��
private:
	int scene; //�V�[��
	Top *top; //�g�b�v���
//	Login login; //���O�C�����
//	SongSelect songSelect; //�ȑI�����
};

#endif