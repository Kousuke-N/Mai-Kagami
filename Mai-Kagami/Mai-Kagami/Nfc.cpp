#include "Nfc.h"

#define PORT 9999	//�|�[�g�ԍ�

void Nfc::Init() 
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);

	
}

int Nfc::GetId()
{
	return 1;
}

bool Nfc::Connect(const char* IP, u_short port)
{
	//sockaddr_in �\���̂̃Z�b�g
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(IP);
	return true;
}