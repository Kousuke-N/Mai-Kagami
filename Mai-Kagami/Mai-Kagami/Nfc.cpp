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

	//	auto thd = std::thread(&Nfc::CheckThread, this);
//	thd.detach();
}

//���[�U�[ID�̎擾
int Nfc::GetId() {
	//printfDx("%d\n", NetHandle);
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

//NFC���`�F�b�N���邽�߂̃X���b�h
void Nfc::CheckThread() {


	//�m�������������ꍇ�̂ݒ��̏���������
	if (NetHandle != -1)
	{
		//�f�[�^������̂�҂�
		while (!ProcessMessage())
		{
			printfDx("ok");
			//�擾���Ă��Ȃ���M�f�[�^�ʂ𓾂�
			DataLength = GetNetWorkDataLength(NetHandle);

			//�擾���Ă��Ȃ���M�f�[�^�ʂ�0����Ȃ��ꍇ�̓��[�v�𔲂���
			if (DataLength != 0) break;
		}



	}

	//WaitKey();
	//id = 1;	//�擾����id��Ԃ�
}