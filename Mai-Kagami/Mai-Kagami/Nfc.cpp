#include "Nfc.h"

#define PORT 9999	//�|�[�g�ԍ�


//NFC�Ǘ��p�N���X�R���X�g���N�^
void Nfc::Init() {
	id = 0;
	//���g���w��IP�A�h���X(127.0�D0.1)��ݒ�
	Ip.d1 = 127;
	Ip.d2 = 0;
	Ip.d3 = 0;
	Ip.d4 = 1;

	//�ʐM���m��
	NetHandle = ConnectNetWork(Ip, PORT);

	if (NetHandle == -1)
		exit(-1);
}

//���[�U�[ID�̎擾
int Nfc::GetId() {
//�擾���Ă��Ȃ���M�f�[�^�ʂ𓾂�
	DataLength = GetNetWorkDataLength(NetHandle);
	//�擾���Ă��Ȃ���M�f�[�^�ʂ�0����Ȃ��ꍇ�̓��[�v�𔲂���
	if (DataLength != 0) {
		//�f�[�^��M
		NetWorkRecv(NetHandle, StrBuf, DataLength);	//�f�[�^���o�b�t�@�Ɏ擾

		//��M�����f�[�^��id��Ԃ�
		printfDx("%s", StrBuf);
		//�ڑ���f��
		CloseNetWork(NetHandle);
	}

	int temp = id;
	return temp;
}

//�ڑ�
bool Nfc::Connect(const char* IP, u_short port)
{
	//sockaddr_in �\���̂̃Z�b�g
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(PORT);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(IP);

	//�\�P�b�g�̐���
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	// �ڑ�
	if (connect(m_DstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {
		return false;
	}
	// �\�P�b�g��񓯊����[�h�ɂ���
	u_long val = 1;
	ioctlsocket(m_DstSocket, FIONBIO, &val);
	return true;
}

//��M
RECVSTATUS Nfc::Recv(char* pData, int DataSize, int *pRecvSize)
{
	int n = recv(m_DstSocket, pData, DataSize, 0);
	if (n < 1) {
		// �f�[�^�����Ă��Ȃ�
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			return RECV_STILL;
			// �ؒfor�G���[
		} else {
			return RECV_FAILED;
		}
	}
	*pRecvSize = n;	// ��M�f�[�^���擾
	return RECV_SUCCESSED;
}