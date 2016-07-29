#include "Song.h"

Song::Song(Font *font, char *title, char *artist, char *folder, int now) {
	n = now;
	char cover[256];
	sprintf_s(cover, sizeof(cover), "song/%s/cover.jpg", folder);
	sprintf_s(music, sizeof(music), "song/%s/music.mp3", folder);
	sprintf_s(movie, sizeof(movie), "song/%s/movie.ogv", folder);
	float x = HEIGHT * 0.35;
	myDrawGraph = new MyDrawGraph(WIDTH * 0.5, x, cover);
	songTitle = new MyDrawTextLine(font, title, WIDTH * 0.79, HEIGHT * 0.3, 1, 30, WIDTH * 0.35, 2); //�e�L�X�g������
	songArtist = new MyDrawText(font, artist, WIDTH * 0.96, HEIGHT * 0.325, 2, 20); //�e�L�X�g������
	songLast[0] = new MyDrawText(font, "�O��@�F --�_", WIDTH * 0.75, HEIGHT * 0.36, 0, 24); //�e�L�X�g������
	songLast[1] = new MyDrawText(font, "�O�X��F --�_", WIDTH * 0.75, HEIGHT * 0.385, 0, 24); //�e�L�X�g������
	myDrawMovie = new MyDrawMovie(WIDTH * 0.44, HEIGHT * 0.57, movie, 0.9);
}

void Song::Load() {
	myDrawGraph->Load();
	playFlag = FALSE;
}

void Song::Release() {
	myDrawGraph->Release();
}

void Song::Update() {
	if (n == 0) {
		myDrawGraph->ChangeEx(1.0);
		myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
	}
	else {
		myDrawGraph->ChangeEx(0.7);
		if (n == -1) {
			myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 - 180);
		}
		else if (n <= 5) {
			myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n);
		}
	}
}

void Song::Draw(int scene) {
	if (n == 0) {
		songTitle->View();
		songArtist->View();
		for (int i = 0; i < 2; i++) {
			songLast[i]->View();
		}
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	}
	if (n >= -1 && n <= 5) {
		myDrawGraph->View();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	switch (scene) {
	case OPTION1:
		if(playFlag)
			StopMusic();
		playFlag = FALSE;
		myDrawMovie->View();
		break;
	default:
		if (n == 0 && !playFlag) {
				PlayMusic(music, DX_PLAYTYPE_LOOP);
			playFlag = TRUE;
		}
		else if (n != 0) {
			playFlag = FALSE;
		}
		speed = 0;
		break;
	}
}

void Song::Change(int num, int max) {
	n += num;
	if (n == -2)
		n = max - 2;
	if (n == max - 1)
		n = -1;
}

void Song::ChangeSpeed(int num) {
	const double s[6] = { 1.0, 0.9, 0.8, 0.7, 0.6, 0.5 };
	if (num == 1 && speed > 0) {
		speed -= 1;
		myDrawMovie->ChangeSpeed(s[speed]);
	}
	if (num == -1 && speed < 5) {
		speed += 1;
		myDrawMovie->ChangeSpeed(s[speed]);
	}
}

void Song::LoadMovie() {
	myDrawMovie->Load();
}

void Song::StopMovie() {
	myDrawMovie->Stop();
}

void Song::ReleaseMovie() {
	myDrawMovie->Release();
}

int Song::GetNow() {
	return n;
}

Song::~Song() {
	delete songTitle;
	delete songArtist;
	for (int i = 0; i < 2; i++) {
		delete songLast[i];
	}
	delete myDrawGraph;
}