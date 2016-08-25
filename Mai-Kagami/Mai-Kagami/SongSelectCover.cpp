#include "SongSelectCover.h"
#include "Animation.h"

SongSelectCover::SongSelectCover(Font *font, Song *song, const int now) 
	: Song(*song) {
	char *folder = "";
	SetNow(now);
}

void SongSelectCover::Load(int max) {
	danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.57);
	danceMovie->ChangeEx(0.5);
	coverGraph->Load();
	//Update(0, max);
	Change(0, max);
	int n = GetNow();
	//int h = 0;
	//if (n == 0)
	//	h = HEIGHT * 0.35;
	//else if (n == -1)
	//	h = HEIGHT * 0.35 - 180;
	//else
	//	h = HEIGHT * 0.35 + 30 + 150 * n;
	coverGraph->ChangePos(WIDTH * 0.5, GetY());
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
	float y = GetY();

	if (n == 0) {
		coverGraph->ChangeEx(1.0);
	}
	else {
		coverGraph->ChangeEx(0.7);
	}

	if (n == -2 && num > 0 || n == max - 3 && num < 0) {
		coverGraph->SetDuration(0);
		coverGraph->SetPosAnimation(WIDTH * 0.5, y);
	}
	else if (coverGraph->GetTime() == 0) { // �ŏ�����
		coverGraph->SetDuration(duration);
		coverGraph->SetPosAnimation(WIDTH * 0.5, y, Animation::EaseOut_SINE);
	}
	coverGraph->Update(); // �A�j���[�V�����X�V
}

void SongSelectCover::Draw(int scene) {
	int n = GetNow();
	if (n != 0)
		coverGraph->SetAlpha(180); //�����x�w��
	else
		coverGraph->SetAlpha(); //�����x����
	if (n <= 6)	// �ړ������l���� 5 ���`��
		coverGraph->View();

	switch (scene) {
	case OPTION1:
		if(playFlag)
			StopMusic();
		playFlag = FALSE;
		danceMovie->Start();
		danceMovie->View();
		break;
	case OPTION2:
		if (playFlag)
			StopMusic();
		playFlag = FALSE;
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
	n = (n + num + max + 2) % max - 2;
	SetNow(n);
}

float SongSelectCover::GetY() {
	int n = GetNow();
	float y;

	n = n < 6 ? n : 6;

	if (n <= -1)
		y =  HEIGHT * 0.35 - 30 + 150 * n;
	else if (n == 0)
		y = HEIGHT * 0.35;
	else
		y = HEIGHT * 0.35 + 30 + 150 * n;

	return y;
}