#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <WS2tcpip.h>
#include <thread>
#include"DxLib.h"
#pragma comment(lib, "ws2_32.lib")

#ifndef _RECVSTATUS_
#define _RECVSTATUS_

//��M���
enum RECVSTATUS
{
	RECV_STILL,		//�f�[�^�����Ă��Ȃ�
	RECV_SUCCESSED,	//����
	RECV_FAILED,	//�ؒfor�G���[
};
#endif

class Nfc 
{
public:
	void Init();	//������
	int GetId();	//���[�U�[ID�̎擾
private:
	IPDATA Ip;			//�ڑ��pIP�A�h���X�f�[�^
	int id;
	int NetHandle;		//�l�b�g���[�N�n���h��
	int DataLength;		//��M�f�[�^�ʕۑ��p�ϐ�
	char StrBuf[256];	//�f�[�^�o�b�t�@
};

#endif