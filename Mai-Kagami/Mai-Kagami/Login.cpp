#include "Login.h"

//�����Z�b�g
void SongHistory::Set(const int history[2]) {
	for (int i = 0; i < 2; i++)
		this->history[i] = history[i];
}

//�����擾
void SongHistory::Get(int *history[2]) {
	for (int i = 0; i < 2; i++)
		*history[i] = this->history[i];
}

Login::Login() {
	for (int i = 0; i < 256; i++)
		songHistory[i] = new SongHistory();
}

//�������[�h
void Login::LoadHistory(const char *userId) {
	//�����ŃT�[�o�ɐڑ����đO��ƑO�X��̓_������M
	//�ȉ��̎������s���邱�Ƃɂ���ăf�[�^��ۑ�
	//songHistory[����ID��]->Set(���O��ƑO�X��̓_���i�z��|�C���^�j��);

	int history[3][2] = { {22, -1}, {44, 55}, {66, 77} };
	for(int i = 0; i < 3; i++)
		songHistory[i + 1]->Set(history[i]);
}

//�����擾
void Login::GetHistory(const int songId, int *history[2]) {
	songHistory[songId]->Get(history);
}

Login::~Login() {
	for (int i = 0; i < 256; i++)
		delete songHistory[i];
}