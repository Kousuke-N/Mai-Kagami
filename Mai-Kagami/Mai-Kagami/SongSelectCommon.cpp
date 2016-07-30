#include "SongSelectCommon.h"

//�ȑI����ʃ^�C�g�����[�h
SongSelectTitle::SongSelectTitle(Font *font, const float x, const float y) 
	: Draw(x, y) {
	title = new MyDrawTextLine(font, "", GetX() * SIZE_RATE, GetY() * SIZE_RATE - HEIGHT * 0.02, 1, 50, WIDTH * 0.4, 3);
	subTitle = new MyDrawText(font, "", GetX() * SIZE_RATE, GetY() * SIZE_RATE + HEIGHT * 0.02, 1, 30, "Yellow");
	scene = -100;
}

//�ȑI����ʃ^�C�g���v�Z
void SongSelectTitle::Update(int scene) {
	if (SongSelectTitle::scene != scene) {
		SongSelectTitle::scene = scene;
		switch (scene)
		{
		case MODE:
			title->ChangeText("Mode Select");
			break;
		case OPTION1:
			title->ChangeText("Option");
			subTitle->ChangeText("�ʂ����K���[�h");
			break;
		default:
			title->ChangeText("Song Select");
			break;
		}
	}
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	title->View(); //�e�L�X�g�\��
	if(scene == OPTION1)
		subTitle->View(); //�e�L�X�g�\��
}

SongSelectTitle::~SongSelectTitle() {
	delete title;
	delete subTitle;
}

//�ȑI����ʃJ�o�[�摜������
SongSelectCover::SongSelectCover(Font *font, Songs *songs) {
	n = songs->GetSongNum();
	for (int i = 0; i < n; i++) {
		song[i] = new Song2(font, songs->GetSong(i), i);
		song[i]->Change(0, n);
	}

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
	songTitle = new MyDrawTextLine(font, "", WIDTH * 0.79, HEIGHT * 0.3, 1, 30, WIDTH * 0.35, 2); //�e�L�X�g������
	songArtist = new MyDrawText(font, "", WIDTH * 0.96, HEIGHT * 0.325, 2, 20); //�e�L�X�g������
	songLast[0] = new MyDrawText(font, "�O��@�F --�_", WIDTH * 0.75, HEIGHT * 0.36, 0, 24); //�e�L�X�g������
	songLast[1] = new MyDrawText(font, "�O�X��F --�_", WIDTH * 0.75, HEIGHT * 0.385, 0, 24); //�e�L�X�g������
}


void SongSelectCover::Load() {
	for (int i = 0; i < 2; i++)
		grad[i]->Load();
	for (int i = 0; i < n; i++)
		song[i]->Load();
}

void SongSelectCover::Update(Touch *touch, int scene) {
	switch (scene)
	{
	case MAIN:
		if (touch->Get(0) == 1) {
			for (int i = 0; i < n; i++)
				song[i]->Change(1, n);
		}

		if (touch->Get(1) == 1)
			song[now]->LoadMovie();
		else {
			for (int i = 0; i < n; i++) {
				if (song[i]->GetNow() == 0) {
					now = i;
					break;
				}
			}
		}

		if (touch->Get(2) == 1) {
			for (int i = 0; i < n; i++)
				song[i]->Change(-1, n);
		}
		for (int i = 0; i < n; i++)
			song[i]->Update();
		break;
	case MODE:
		if (touch->Get(4) == 1)
			song[now]->ReleaseMovie();
		break;
	case OPTION1:
		if (touch->Get(0) == 1)
			song[now]->ChangeSpeed(1);
		if (touch->Get(1) == 1)
			song[now]->ChangeSpeed(-1);
		if (touch->Get(4) == 1)
			song[now]->StopMovie();
	}
}

//�ȑI����ʃJ�o�[�摜�\��
void SongSelectCover::View(int scene) {
	switch (scene)
	{
	case BACK:
	case MAIN:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
		myDrawBox->View();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		box->View();
		for (int i = 0; i < n; i++)
			song[i]->Draw(scene);
		for (int i = 0; i < 2; i++)
			grad[i]->View();
		break;
	case MODE:
	case OPTION1:
		song[now]->Draw(scene);
		break;
	}
}

void SongSelectCover::Release() {
	for (int i = 0; i < 2; i++)
		grad[i]->Release();
	for (int i = 0; i < n; i++)
		song[i]->Release();
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