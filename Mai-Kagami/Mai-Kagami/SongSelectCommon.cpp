#include "SongSelectCommon.h"

//�ȑI����ʃ^�C�g�����[�h
SongSelectTitle::SongSelectTitle(Font *font) {
	char *str = "Song Select"; //�\��������
	myDrawText = new MyDrawText(font, str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //�e�L�X�g������
	subTitle = new MyDrawText(font, "", WIDTH * 0.65, HEIGHT * 0.245, 1, 30, "Yellow"); //�e�L�X�g������
	myDrawLine = new MyDrawLine(WIDTH * 0.65, HEIGHT * 0.236, 1, WIDTH * 0.4, 3); //��������
}

//�ȑI����ʃ^�C�g���v�Z
void SongSelectTitle::Update(int scene) {
	switch (scene)
	{
	case MODE:
		myDrawText->ChangeText("Mode Select");
		break;
	case OPTION1:
		myDrawText->ChangeText("Option");
		subTitle->ChangeText("�ʂ����K���[�h");
		break;
	default:
		myDrawText->ChangeText("Song Select");
		break;
	}
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	myDrawText->Draw(); //�e�L�X�g�\��
	subTitle->Draw(); //�e�L�X�g�\��
	myDrawLine->Draw(); //���\��
}

SongSelectTitle::~SongSelectTitle() {
	delete myDrawText;
	delete subTitle;
	delete myDrawLine;
}

//�ȑI����ʃJ�o�[�摜������
SongSelectCover::SongSelectCover(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	while (FileRead_scanf(file, "%[^,\n\r],%[^,\n\r],%[^\n\r]", buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, buf[1], buf[2], buf[0], n);
		n++;
	}
	FileRead_close(file);

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
}

void SongSelectCover::Update(Touch *touch) {
	if (touch->Get(0) == 1 && song[0]->GetNow() < 0) {
		for (int i = 0; i < n; i++)
			song[i]->Change(1);
	}

	if (touch->Get(1) == 1) {
		drawFlag = FALSE;

	}
	else {
		drawFlag = TRUE;
		for (int i = 0; i < n; i++) {
			if (song[i]->GetNow() == 0) {
				now = i;
				break;
			}
		}
	}

	if (touch->Get(2) == 1 && song[n - 1]->GetNow() > 0) {
		for (int i = 0; i < n; i++)
			song[i]->Change(-1);
	}
	for (int i = 0; i < n; i++)
		song[i]->Update();
}

//�ȑI����ʃJ�o�[�摜�\��
void SongSelectCover::View() {
	if (drawFlag) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
		myDrawBox->Draw();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		box->Draw();
		for (int i = 0; i < n; i++)
			song[i]->Draw();
		for (int i = 0; i < 2; i++)
			grad[i]->Draw();
	}
	else {
//		box->Draw();
		song[now]->Draw();
	}
}

SongSelectCover::~SongSelectCover() {
	delete box;
	delete myDrawBox;
	for (int i = 0; i < n; i++)
		delete song[i];
	for (int i = 0; i < 2; i++) {
		delete grad[i];
	}
}