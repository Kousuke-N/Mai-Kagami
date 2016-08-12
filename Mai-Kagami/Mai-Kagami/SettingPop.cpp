#include "SeetingPop.h"

//�|�b�v�A�b�v�p�l�p�`�i���F�������S��ʁj
BlackBox::BlackBox()
	: MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black") {}

void BlackBox::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //�����x�ݒ�
	MyDrawBox::View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

SpeedOption::SpeedOption(Font *font, Songs *songs) {
	button[0] = new TriangleButton(font, "UP", 0, 0);
	button[1] = new TriangleButton(font, "DOWN", 1, 1);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "�X�s�[�h", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "�~1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
	SpeedOption::songs = songs;
}

void SpeedOption::Check(Touch *touch) {
	Song *song = songs->GetSong(songs->GetNowSong());
	if (touch->Get(0) == 1)
		song->ChangeSpeed(1);
	if (touch->Get(1) == 1)
		song->ChangeSpeed(-1);
	char str[256];
	sprintf_s(str, sizeof(str), "�~%1.1lf", song->danceMovie->GetSpeed());
	speed[1]->ChangeText(str);
}

void SpeedOption::View() {
	for (int i = 0; i < 2; i++) {
		button[i]->View();
		speed[i]->View();
	}
}

SpeedOption::~SpeedOption() {
	for (int i = 0; i < 2; i++) {
		delete button[i];
		delete speed[i];
	}
}

//�X�s�[�h�I�v�V�����|�b�v�A�b�v
SpeedPop::SpeedPop(Font *font, Songs *songs)
	: SpeedOption(font, songs) {
	SpeedPop::songs = songs;
	blackBox = new BlackBox();
	button = new CircleButton2(font, "����", 4);
	text = new MyDrawText(font, "- ���x�ݒ� -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40);
}

void SpeedPop::Check(Touch *touch) {
	Song *song = songs->GetSong(songs->GetNowSong());
	SpeedOption::Check(touch);
	if (touch->Get(4) == 1)
		song->danceMovie->SetSpeed();
}

void SpeedPop::View() {
	blackBox->View();
	SpeedOption::View();
	button->View();
	text->View();
}

SpeedPop::~SpeedPop() {
	delete blackBox;
	delete button;
	delete text;
}