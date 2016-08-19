#include "Nfc.h"

#define PORT 9999		//�|�[�g�ԍ�
#define IP "127.0.0.1"	//IP�ԍ�(���[�J���z�X�g) 

void Nfc::Init() 
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
}

int Nfc::GetId()
{
	int recvsize;				//��M�f�[�^��
	char recvMessage[5] = {};	//��M�X�g���[��
	char data[256] = {};		//��M����ID���i�[����ϐ�

	//�ڑ��Ɏ��s�����Ƃ��̃G���[����
	if (!Connect(IP, PORT)) {
		return -1;
	}

	//��M
	while (true) {
		RECVSTATUS status = Recv(
			recvMessage,		//��M�f�[�^�i�[�p�̔z�� 
			sizeof(recvsize),	//��M�f�[�^��
			&recvsize);			//��M�f�[�^���̃|�C���^
		switch (status) {
		case RECV_STILL:
			printfDx("0");
			continue;
		case RECV_SUCCESSED:
			printfDx("�󂯎��܂���:%s\n", data);
			strcat(data, recvMessage);
			continue;
		case RECV_FAILED:
			printfDx("�󂯎��Ɏ��s���܂���\n");
			break;
		}
		break;
	}
	printfDx("��M�f�[�^:%s", data);

	return 1;
}

//�ڑ�
bool Nfc::Connect(const char* Ip, u_short Port)
{
	//sockaddr_in �\���̂̃Z�b�g
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(Port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(Ip);

	//�\�P�b�g�̐���
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	//�ڑ�
	if (connect(m_DstSocket, (struct sockaddr *) & dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {
		return false;
	}
	//�\�P�b�g��񓯊����[�h�ɂ���
	u_long val = 1;
	ioctlsocket(m_DstSocket, FIONBIO, &val);
	return true;
}

//��M
RECVSTATUS Nfc::Recv(char* pData, int DataSize, int *pRecvSize) 
{
	int n = recv(m_DstSocket, pData, DataSize, 0);
	if (n < 1) {
		//�f�[�^�����Ă��Ȃ�
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			return RECV_STILL;
		//�ؒfor�G���[
		} else {
			return RECV_FAILED;
		}
	}
	*pRecvSize = n;	//��M�f�[�^���擾
	return RECV_SUCCESSED;
}