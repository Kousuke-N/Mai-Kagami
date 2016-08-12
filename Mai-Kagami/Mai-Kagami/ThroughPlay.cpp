#include "ThroughPlay.h"

//�i���o�[
ThroughPlayBar::ThroughPlayBar(Font *font) {
	barAll = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, WIDTH * 0.56, 10);
	barNow = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, 0, 10, "Blue");
	circle[0] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 12);
	circle[1] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 5, "White");
	ThroughPlayBar::font = font;
}

void ThroughPlayBar::Load(Song *song) {
	ThroughPlayBar::song = song;
	song->LoadPart();
	for (int i = 0; i < song->GetPartNum(); i++) {
		SongPart *songPart = song->GetPart(i);
		float x = WIDTH * 0.41 + WIDTH * 0.56 * (float)songPart->GetFlame() / song->danceMovie->GetAllFlame();
		part[i] = new MyDrawTextV(font, songPart->GetName(), x, HEIGHT * 0.054, 0, 16);
	}
}

void ThroughPlayBar::Update() {
	int nowFlame = song->danceMovie->GetNowFlame();
	int lastFlame = song->danceMovie->GetAllFlame();
	float now = WIDTH * 0.56 * nowFlame / lastFlame;
	barNow->ChangeSize(now, 10);
	for (int i = 0; i < 2; i++)
		circle[i]->ChangePos(WIDTH * 0.41 + now, HEIGHT * 0.055);
	for (int i = song->GetPartNum() - 1; i >= 0; i--) {
		SongPart *songPart = song->GetPart(i);
		if (nowFlame < lastFlame && nowFlame >= songPart->GetFlame()) {
			part[i]->ChangeColor("Blue");
			part[i]->ChangeFont(font, 20);
		}
		else {
			part[i]->ChangeColor("White");
			part[i]->ChangeFont(font, 16);
		}
		lastFlame = songPart->GetFlame();
	}
}

void ThroughPlayBar::View() {
	barAll->View();
	barNow->View();
	for (int i = 0; i < 2; i++)
		circle[i]->View();
	for (int i = 0; i < song->GetPartNum(); i++)
		part[i]->View();
}

ThroughPlayBar::~ThroughPlayBar() {
	delete barAll;
	delete barNow;
	for (int i = 0; i < 2; i++)
		delete circle[i];
}

//�J�E���g�_�E����ʍĐ��O�p�`
PlayTriangle::PlayTriangle(const float x, const float y) 
	: MyDrawTriangle("Yellow") {
	const float w = 100, ex = 12;
	float x1 = x - w + ex, x2 = x - w + ex, x3 = x + w + ex;
	float y1 = y + w, y2 = y - w, y3 = y;
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//�J�E���g�_�E�����
ThroughCountDown::ThroughCountDown(Font *font) {
	const float x = WIDTH * 0.5; //�~�̒��S�ix���W�j
	const float y = HEIGHT * 0.5; //�~�̒��S�iy���W�j
	const float r = WIDTH * 0.2; //�~�̔��a
	blackBox = new BlackBox();
	text = new MyDrawText(font, "���������Ă�������", x, y + r + 80, 1, 40);
	circle = new MyDrawCircle(x, y, r, "White");
	countCircle1 = new MyDrawCircleGauge(x, y, r, 0, 4, "Yellow");
	countCircle2 = new MyDrawCircle(0, 0, 12, "Yellow");
	playTriangle = new PlayTriangle(x, y);
}

void ThroughCountDown::Update() {
	countCircle1->ChangeDegree((double)count / max * 100);
	countCircle2->ChangePos(countCircle1->GetEndX() * SIZE_RATE, countCircle1->GetEndY() * SIZE_RATE);
	if (++count == max)
		flag = FALSE;
}

void ThroughCountDown::View() {
	blackBox->View();
	text->View();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //�����x�ݒ�
	circle->View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
	countCircle1->View();
	countCircle2->View();
	playTriangle->View();
}

boolean ThroughCountDown::GetFlag() {
	return flag;
}

void ThroughCountDown::SetFlag(const boolean flag) {
	ThroughCountDown::flag = flag;
	if (flag == TRUE)
		count = 0;
}

ThroughCountDown::~ThroughCountDown() {
	delete blackBox;
	delete text;
	delete circle;
	delete countCircle1;
	delete countCircle2;
	delete playTriangle;
}

ThroughPlay::ThroughPlay(Font *font) {
	ThroughPlay::font = font;
	throughPlayBar = new ThroughPlayBar(font);
	throughCountDown = new ThroughCountDown(font);
}

void ThroughPlay::Load(Song *song) {
	ThroughPlay::song = song;
	song->danceMovie->ChangeEx(1.2);
	song->danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.5);
	song->danceMovie->Seek();
	song->drawSongTitle->ChangePos(WIDTH * 0.2, HEIGHT * 0.03);

	throughPlayBar->Load(song);
	throughCountDown->SetFlag(TRUE);
}

void ThroughPlay::Update(int scene) {
	ThroughPlay::scene = scene;
	throughPlayBar->Update();
	switch (scene)
	{
	case THROUGH_PLAY:
		if (throughCountDown->GetFlag())
			throughCountDown->Update();
		else
			song->danceMovie->Start();
		break;
	default:
		throughCountDown->SetFlag(TRUE);
		song->danceMovie->Stop();
		break;
	}
}

void ThroughPlay::View() {
	song->danceMovie->View();
	song->drawSongTitle->View();
	throughPlayBar->View();
	if (scene == THROUGH_PLAY && throughCountDown->GetFlag())
		throughCountDown->View();
}

ThroughPlay::~ThroughPlay() {
	delete throughPlayBar;
}