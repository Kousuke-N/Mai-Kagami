#include "SongSelect.h"

//�ȑI����ʃ^�C�g�����[�h
void SongSelectTitle::Init() {
	int strLen; //������̒���

	str = "Song Select"; //�\��������
	font.Set(50); //�t�H���g�T�C�Y�Z�b�g
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	x = WIDTH / 2 - strLen / 2;
	y = HEIGHT * 0.2;
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	Color color;

	DrawStringToHandle(x, y, str, color.White(), font.Get()); //�����\��
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
	songSelectTitle.View();
}

//�ȑI����ʉ摜���[�h
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //�ȑI����ʃ^�C�g��������
	Sleep(10000);
	loadFlag = 2;
}