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

bool Connect(const char* IP, u_short port)
{

}