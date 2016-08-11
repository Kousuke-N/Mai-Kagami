#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <thread>
#include"DxLib.h"

class Nfc {
public:
	void Init();
	int GetId(); //���[�U�[ID�̎擾
private:
	void CheckThread(); //NFC���`�F�b�N���邽�߂̃X���b�h
	int id;
	IPDATA Ip;	//�ڑ��pIP�A�h���X�f�[�^
	int NetHandle;	//�l�b�g���[�N�n���h��
	int DataLength;	//��M�f�[�^�ʕۑ��p�ϐ�
	char StrBuf[256];	//�f�[�^�o�b�t�@
};

#endif