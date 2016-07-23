#include "SongSelect.h"

//�ȑI����ʃ^�C�g�����[�h
void SongSelectTitle::Init() {
	char *str = "Song Select"; //�\��������
	myDrawText.Init(str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //�e�L�X�g������
	myDrawLine.Init(WIDTH * 0.65, HEIGHT * 0.24, 1, myDrawText.GetWidth() + 10, 20); //��������
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	myDrawText.Draw(); //�e�L�X�g�\��
	myDrawLine.Draw(); //���\��
}

//�ȑI����ʃJ�o�[�摜������
void SongSelectCover::Init() {
	myDrawGraph.Init(WIDTH * 0.52, HEIGHT * 0.35, "song/Ghost_Rule/cover.jpg");
	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

//�ȑI����ʃJ�o�[�摜�\��
void SongSelectCover::View() {
	myDrawGraph.Draw();
}

//�ȑI����ʃ{�^��������
void SongSelectButton::Init() {
	char *str[4] = { "�O�̋Ȃ�", "����", "���̋Ȃ�" }; //�\��������
	myDrawText[0].Init(str[0], WIDTH * 0.94, BUTTON1_POS - HEIGHT * 0.0085, 2, 30);
	myDrawTriangle[0].Init(WIDTH * 0.97, BUTTON1_POS, WIDTH * 0.03, 0);
	myDrawText[1].Init(str[1], WIDTH * 0.94, BUTTON2_POS - HEIGHT * 0.0085, 2, 30);
	myDrawRing.Init(WIDTH * 0.97, BUTTON2_POS, WIDTH * 0.015, 7);
	myDrawText[2].Init(str[2], WIDTH * 0.94, BUTTON3_POS - HEIGHT * 0.0085, 2, 30);
	myDrawTriangle[1].Init(WIDTH * 0.97, BUTTON3_POS, WIDTH * 0.03, 1);
	finish.Init("�I��", WIDTH * 0.955, BUTTON5_POS - HEIGHT * 0.0085, 1, 30);
	finishCircle.Init(WIDTH * 0.955, BUTTON5_POS, WIDTH * 0.042);
}

//�ȑI����ʃ{�^���\��
void SongSelectButton::View() {
	myDrawText[0].Draw();
	myDrawText[1].Draw();
	myDrawText[2].Draw();
	myDrawTriangle[0].Draw();
	myDrawTriangle[1].Draw();
	finishCircle.Draw();
	finish.Draw();
	myDrawRing.Draw();
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
	songSelectCover.View(); //�J�o�[�\��
	songSelectButton.View(); //�{�^���\��
}

//�ȑI����ʉ摜���[�h
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //�ȑI����ʃ^�C�g��������
	songSelectCover.Init(); //�I�𒆂̋ȏ�����
	songSelectButton.Init();
//	Sleep(5000);
	loadFlag = 2;
}