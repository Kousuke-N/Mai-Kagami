#include "Nfc.h"


//NFC�Ǘ��p�N���X�R���X�g���N�^
Nfc::Nfc() {
	id = 0;
	auto thd = std::thread(&Nfc::CheckThread, this);
	thd.detach();
}

//���[�U�[ID�̎擾
int Nfc::GetId() {
	return id;
}

//NFC���`�F�b�N���邽�߂̃X���b�h
void Nfc::CheckThread() {
	WaitKey();
	id = 1;
}