#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <thread>
#include"DxLib.h"

class Nfc 
{
public:
	void Init();	//������
	int GetId();	//���[�U�[ID�̎擾

private:
	IPDATA Ip;			//�ڑ��pIP�A�h���X�f�[�^
	int id;				//�擾����ID
	int NetHandle;		//�l�b�g���[�N�n���h��
	int DataLength;		//��M�f�[�^�ʕۑ��p�ϐ�
	char StrBuf[256];	//�f�[�^�o�b�t�@
};

#endif