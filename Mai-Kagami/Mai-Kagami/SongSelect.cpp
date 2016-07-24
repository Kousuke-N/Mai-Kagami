#include "SongSelect.h"

//�ȑI����ʃ^�C�g�����[�h
SongSelectTitle::SongSelectTitle() {
	char *str = "Song Select"; //�\��������
	myDrawText = new MyDrawText(str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //�e�L�X�g������
	myDrawLine = new MyDrawLine(WIDTH * 0.65, HEIGHT * 0.236, 1, WIDTH * 0.4, 20); //��������
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	myDrawText->Draw(); //�e�L�X�g�\��
	myDrawLine->Draw(); //���\��
}

SongSelectTitle::~SongSelectTitle() {
	delete myDrawText;
	delete myDrawLine;
}

//�ȑI����ʃJ�o�[�摜������
SongSelectCover::SongSelectCover() {
	char *title = "�S�[�X�g���[��"; //�\��������
	char *artist = "�����~�N / DECO*27";
	float x = HEIGHT * 0.35;
	myDrawGraph = new MyDrawGraph(WIDTH * 0.52, x, "song/Ghost_Rule/cover.jpg");
	songTitle = new MyDrawText(title, WIDTH * 0.8, HEIGHT * 0.29, 1, 36); //�e�L�X�g������
	songArtist = new MyDrawText(artist, WIDTH * 0.96, HEIGHT * 0.32, 2, 20); //�e�L�X�g������
	songLast[0] = new MyDrawText("�O��@�F --�_", WIDTH * 0.75, HEIGHT * 0.355, 0, 24); //�e�L�X�g������
	songLast[1] = new MyDrawText("�O�X��F --�_", WIDTH * 0.75, HEIGHT * 0.38, 0, 24); //�e�L�X�g������
	myDrawLine = new MyDrawLine(WIDTH * 0.8, HEIGHT * 0.315, 1, WIDTH * 0.33, 6); //��������
	myDrawBox = new MyDrawBox(WIDTH * 0.52, HEIGHT * 0.5, 170, 1000);
	songCover[0] = new MyDrawGraph(WIDTH * 0.52, x - 180, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[1] = new MyDrawGraph(WIDTH * 0.52, x + 180, "song/Happy_Synthesizer/cover.jpg", 0.7);
	songCover[2] = new MyDrawGraph(WIDTH * 0.52, x + 330, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[3] = new MyDrawGraph(WIDTH * 0.52, x + 480, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[4] = new MyDrawGraph(WIDTH * 0.52, x + 630, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[5] = new MyDrawGraph(WIDTH * 0.52, x + 780, "song/Ghost_Rule/cover.jpg", 0.7);
	grad[0] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.52, x, "img/box.png");
	//	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

//�ȑI����ʃJ�o�[�摜�\��
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	for(int i = 0; i < 6; i++)
		songCover[i]->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box->Draw();
	myDrawGraph->Draw();
	songTitle->Draw();
	songArtist->Draw();
	for (int i = 0; i < 2; i++) {
		songLast[i]->Draw();
		grad[i]->Draw();
	}
	myDrawLine->Draw();
}

SongSelectCover::~SongSelectCover() {
	delete songTitle;
	delete songArtist;
	for (int i = 0; i < 2; i++) {
		delete songLast[i];
		delete grad[i];
	}
	delete myDrawLine;
	delete myDrawGraph;
	for (int i = 0; i < 6; i++)
		delete songCover[i];
	delete box;
	delete myDrawBox;
}

//�ȑI����ʃ{�^��������
SongSelectButton::SongSelectButton() {
	button[0] = new Button("�O�̋Ȃ�", 1, 0);
	button[1] = new Button("����", 0, 1);
	button[2] = new Button("���̋Ȃ�", 2, 2);
	button[3] = new Button("�I��", 3, 4);
}

//�ȑI����ʃ{�^���\��
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->Draw();
}

SongSelectButton::~SongSelectButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}

//�ȑI����ʃ��[�h
boolean SongSelect::Load() {
	if (loadFlag == 0) {
		songSelectTitle = new SongSelectTitle(); //�ȑI����ʃ^�C�g��������
		songSelectCover = new SongSelectCover(); //�I�𒆂̋ȏ�����
		songSelectButton = new SongSelectButton();
		loadFlag = 2;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;

	if (loadFlag == 2)
		return TRUE;
	return FALSE;
}

SongSelect::SongSelect() {
	loadFlag = 0;
}


//�ȑI����ʌv�Z
int SongSelect::Update() {
	if (Load()) {
		touch.Check();
		if (touch.Get(4) != 0) {
			Delete();
			return TOP;
		}
	}
	return SONG_SELECT;
}

//�ȑI����ʕ\��
void SongSelect::View(Loading *loading) {
	if (loadFlag == 2) {
		songSelectCover->View(); //�J�o�[�\��
		songSelectButton->View(); //�{�^���\��
		songSelectTitle->View(); //�^�C�g���\��
	}
	else {
		loading->View();
	}
}

void SongSelect::Delete() {
	loadFlag = 0;
	delete songSelectCover;
	delete songSelectButton;
	delete songSelectTitle;
}