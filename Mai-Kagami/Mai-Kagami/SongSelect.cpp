#include "SongSelect.h"
/*
//�ȑI����ʃ^�C�g�����[�h
void SongSelectTitle::Init() {
	char *str = "Song Select"; //�\��������
	myDrawText.Init(str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //�e�L�X�g������
	myDrawLine.Init(WIDTH * 0.65, HEIGHT * 0.236, 1, myDrawText.GetWidth() + 10, 20); //��������
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	myDrawText.Draw(); //�e�L�X�g�\��
	myDrawLine.Draw(); //���\��
}

//�ȑI����ʃJ�o�[�摜������
void SongSelectCover::Init() {
	char *title = "�S�[�X�g���[��"; //�\��������
	char *artist = "�����~�N / DECO*27";
	float x = HEIGHT * 0.35;
	myDrawGraph.Init(WIDTH * 0.52, x, "song/Ghost_Rule/cover.jpg");
	songTitle.Init(title, WIDTH * 0.8, HEIGHT * 0.29, 1, 36); //�e�L�X�g������
	songArtist.Init(artist, WIDTH * 0.96, HEIGHT * 0.32, 2, 20); //�e�L�X�g������
	songLast[0].Init("�O��@�F --�_", WIDTH * 0.75, HEIGHT * 0.355, 0, 24); //�e�L�X�g������
	songLast[1].Init("�O�X��F --�_", WIDTH * 0.75, HEIGHT * 0.38, 0, 24); //�e�L�X�g������
	myDrawLine.Init(WIDTH * 0.8, HEIGHT * 0.315, 1, WIDTH * 0.33, 6); //��������
	myDrawBox.Init(WIDTH * 0.52, HEIGHT * 0.5, 170, 1000);
	songCover[0].Init(WIDTH * 0.52, x - 180, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[1].Init(WIDTH * 0.52, x + 180, "song/Happy_Synthesizer/cover.jpg", 0.7);
	songCover[2].Init(WIDTH * 0.52, x + 330, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[3].Init(WIDTH * 0.52, x + 480, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[4].Init(WIDTH * 0.52, x + 630, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[5].Init(WIDTH * 0.52, x + 780, "song/Ghost_Rule/cover.jpg", 0.7);
	grad[0].Init(WIDTH * 0.52, HEIGHT * 0.22, "img/grad1.png");
	grad[1].Init(WIDTH * 0.52, HEIGHT * 0.8, "img/grad2.png");
	box.Init(WIDTH * 0.52, x, "img/box.png");
	//	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

//�ȑI����ʃJ�o�[�摜�\��
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox.Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	songCover[0].Draw();
	songCover[1].Draw();
	songCover[2].Draw();
	songCover[3].Draw();
	songCover[4].Draw();
	songCover[5].Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box.Draw();
	myDrawGraph.Draw();
	songTitle.Draw();
	songArtist.Draw();
	songLast[0].Draw();
	songLast[1].Draw();
	myDrawLine.Draw();
	grad[0].Draw();
	grad[1].Draw();
}

//�ȑI����ʃ{�^��������
void SongSelectButton::Init() {
	button[0].Init("�O�̋Ȃ�", 1, 0);
	button[1].Init("����", 0, 1);
	button[2].Init("���̋Ȃ�", 2, 2);
	button[3].Init("�I��", 3, 4);
}

//�ȑI����ʃ{�^���\��
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i].Draw();
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
int SongSelect::Update() {
	touch.Check();
	if (touch.Get(4) != 0)
		return TOP;
	return SONG_SELECT;
}

//�ȑI����ʕ\��
void SongSelect::View() {
	songSelectCover.View(); //�J�o�[�\��
	songSelectButton.View(); //�{�^���\��
	songSelectTitle.View(); //�^�C�g���\��
}

//�ȑI����ʉ摜���[�h
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //�ȑI����ʃ^�C�g��������
	songSelectCover.Init(); //�I�𒆂̋ȏ�����
	songSelectButton.Init();
//	Sleep(5000);
	loadFlag = 2;
}*/