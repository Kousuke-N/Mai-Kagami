#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <WinSock2.h>
#include <Ws2tcpip.h>
#include "DxLib.h"
#pragma comment(lib, "ws2_32.lib")

#ifndef _RECVSTATUS_
#define _RECVSTATUS_

//��M���
enum RECVSTATUS
{
	RECV_STILL,		//�f�[�^�����Ă��Ȃ�
	RECV_SUCCESSED,	//����
	RECV_FAILED		//�ؒfor�G���[
};

#endif

class Nfc 
{
public:
	//������
	void Init();
	//���[�U�[ID�̎擾
	char* GetId();
	//�\�P�b�g�Ƃ̐ڑ�
	bool Connect(const char* Ip, u_short Port);	
	//��M
	RECVSTATUS Recv(char* pData, int DataSize, int *pRecvSize);
private:
	SOCKET m_DstSocket;
};

#endif