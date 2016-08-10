#ifndef _CLIENT_H_
#define _CLIENT_H_

//WSAStartup	�J�n
//socket		�\�P�b�g�쐬
//connect		�T�[�o�ɐڑ�
//ioctlsocket	�\�P�b�g�񓯊���
//recv,send		�f�[�^����M
//closesocket	�\�P�b�g����
//WSACleanup	�I��

#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#ifndef _RECVSTATUS_
#define _RECVSTATUS_

enum RECVSTATUS
{
	RECV_STILL,		//�f�[�^�����Ă��Ȃ�
	RECV_SUCCESSED,	//����
	RECV_FAILED		//�ؒfor�G���[
};

#endif

class CClient
{
public:
	//�R���X�g���N�^
	CClient();
	//�f�X�g���N�^
	virtual ~CClient();

	//�ڑ�
	bool Connect(const char* IP, u_short PORT);

	//��M
	RECVSTATUS Recv(char* pData, int DataSize, int* pRecvSize);
	//���M
	bool Send(char* pData, int DataSize);

private:
	SOCKET m_DstSocket;
};

#endif