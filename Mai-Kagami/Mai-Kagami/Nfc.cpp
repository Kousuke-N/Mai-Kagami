#include "Nfc.h"

#define PORT 9999;	//�|�[�g�ԍ�


//NFC�Ǘ��p�N���X�R���X�g���N�^
void Nfc::Init() {
	id = 0;
	auto thd = std::thread(&Nfc::CheckThread, this);
	thd.detach();
}

//���[�U�[ID�̎擾
int Nfc::GetId() {
	int temp = id;
	return temp;
}

//NFC���`�F�b�N���邽�߂̃X���b�h
void Nfc::CheckThread() {
	WaitKey();
	id = 1;	//�擾����id��Ԃ�
}