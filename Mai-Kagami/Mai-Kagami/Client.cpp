#include "Client.h"

//�R���X�g���N�^
CClient::CClient() :m_DstSocket(INVALID_SOCKET)
{
}

//�f�X�g���N�^
CClient::~CClient() {
}

//�ڑ�
bool CClient::Connect(const char* IP, u_short PORT)
{
	return true;
}

//��M
RECVSTATUS CClient::Recv(char* pData, int DataSize, int *pRecvSize)
{
	return RECV_SUCCESSED;
}

//���M
bool CClient::Send(char*pData, int DataSize)
{
	return true;
}