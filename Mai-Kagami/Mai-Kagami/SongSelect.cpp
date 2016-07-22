#include "SongSelect.h"

//�ȑI����ʃ^�C�g�����[�h
void SongSelectTitle::Init() {
	char *str = "Song Select"; //�\��������
	myDrawText.Init(str, WIDTH / 2, HEIGHT * 0.2, 1, 70); //�e�L�X�g������
	myDrawLine.Init(WIDTH / 2, HEIGHT * 0.3, 1, 1000, 20); //��������
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	myDrawText.Draw(); //�e�L�X�g�\��
	myDrawLine.Draw(); //���\��
}

//�ȑI����ʃ��[�h
int SongSelect::Load() {
	if (loadFlag == 0) {
		auto thd = std::thread(&SongSelect::LoadThread, this);
		thd.detach();
		loadFlag = 1;
	}
	if (loadFlag == 2)
		return SONG_SELECT;
	return LOGIN;
}

//�ȑI����ʌv�Z
void SongSelect::Update() {
}

//�ȑI����ʕ\��
void SongSelect::View() {
	songSelectTitle.View(); //�^�C�g���\��
}

//�ȑI����ʉ摜���[�h
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //�ȑI����ʃ^�C�g��������
	Sleep(500);
	loadFlag = 2;
}