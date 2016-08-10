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
	button[2] = new CircleButton2(font, "����", 4);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "�X�s�[�h", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "�~1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
	SpeedOption::songs = songs;
}

void SpeedOption::Update() {
	Song *song = songs->GetSong(songs->GetNowSong());

	char str[256];
	sprintf_s(str, sizeof(str), "�~%1.1lf", song->danceMovie->GetSpeed());
	speed[1]->ChangeText(str);
}

void SpeedOption::View() {
	for (int i = 0; i < 3; i++)
		button[i]->View();
	for (int i = 0; i < 2; i++)
		speed[i]->View();
}

SpeedOption::~SpeedOption() {
	for (int i = 0; i < 3; i++)
	delete button[i];
for (int i = 0; i < 2; i++)
	delete speed[i];
}

//�X�s�[�h�I�v�V�����|�b�v�A�b�v
SpeedPop::SpeedPop(Font *font, Songs *songs)
	: SpeedOption(font, songs) {
	blackBox = new BlackBox();
}

void SpeedPop::View() {
	blackBox->View();
	SpeedOption::View();
}

void SpeedPop::Update() {
	SpeedOption::Update();
}

SpeedPop::~SpeedPop() {
	delete blackBox;
}