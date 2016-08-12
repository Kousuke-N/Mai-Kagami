#include "SongSelectCover.h"

SongSelectCover::SongSelectCover(Font *font, Song *song, const int now) 
	: Song(*song) {
	char *folder = "";
	SetNow(now);
}

void SongSelectCover::Load() {
	danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.57);
	danceMovie->ChangeEx(0.5);
	coverGraph->Load();
	playFlag = FALSE;
}

void SongSelectCover::Release() {
	coverGraph->Release();
}

//�\���ʒu�̌v�Z
void SongSelectCover::Update(int num, int max) {
	//static int t = 0;	// �ז� Jaity
	Change(num, max);
	int n = GetNow();
	int duration = 10;

	if (n == 0) {
		coverGraph->ChangeEx(1.0);
		if (coverGraph->GetTime() == 0) { // �ŏ�����
			coverGraph->SetPosAnimation(WIDTH * 0.5, HEIGHT * 0.35, duration);
			//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
		}
		//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
		//coverGraph->Update();
	}
	else {
		coverGraph->ChangeEx(0.7);
		if (coverGraph->GetTime() == 0) { // �ŏ�����
			if (n == -1) {
				//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 - 180);
				coverGraph->SetPosAnimation(WIDTH * 0.5, HEIGHT * 0.35 - 180, duration);
			}
			else if (n <= 5) {
				//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n);
				coverGraph->SetPosAnimation(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n, duration);
			}
		}
	}
	coverGraph->Update();
	//if (t < 1000)	// �ז� Jaity
	//	t++;		// �ז� Jaity
}

void SongSelectCover::Draw(int scene) {
	int n = GetNow();
	if (n != 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	}
	if (n >= -1 && n <= 5) {
		coverGraph->View();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	switch (scene) {
	case OPTION1:
		if(playFlag)
			StopMusic();
		playFlag = FALSE;
		danceMovie->Start();
		danceMovie->View();
		break;
	default:
		if (n == 0 && !playFlag) {
//			PlayMusic(music, DX_PLAYTYPE_LOOP); // �d���̂ňꎞ�I�ɏ��� Jaity
			playFlag = TRUE;
		}
		else if (n != 0) {
			playFlag = FALSE;
		}
		break;
	}
}

//�Ȃ̈ʒuID��ύX
void SongSelectCover::Change(int num, int max) {
	int n = GetNow();
	n += num;
	if (n == -2)
		n = max - 2;
	if (n == max - 1)
		n = -1;
	SetNow(n);
}