#include "ThroughPause.h"

ThroughPause::ThroughPause(Font *font, Songs *songs) {
	pauseButton = new CircleGraphButton(0, "img/pause.png");
	blackBox = new BlackBox();
	title = new MyDrawText(font, "- �|�[�Y -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40, "Yellow");
	button[0] = new CircleGraphTextButton(font, "�߂�", 0, "img/play.png");
	button[1] = new CircleGraphTextButton(font, "�͂��߂���", 1, "img/rewind.png");
	button[2] = new CircleGraphTextButton(font, "�ȑI����", 2, "img/back.png");
	button[3] = new CircleGraphTextButton(font, "�ݒ�ύX", 3, "img/setting.png");
	speedPop = new SpeedPop(font, songs);
	flag = FALSE;
}

void ThroughPause::Check(Touch *touch) {
	speedPop->Check(touch);
}

void ThroughPause::Update(const int scene) {
	ThroughPause::scene = scene;
}

void ThroughPause::Load() {
	pauseButton->Load();
	for (int i = 0; i < 4; i++)
		button[i]->Load();
}

void ThroughPause::View() {
	if (scene == THROUGH_PAUSE) {
		blackBox->View();
		title->View();
		for (int i = 0; i < 4; i++)
			button[i]->View();
	}
	else if (scene == THROUGH_SETTING) {
		speedPop->View();
	}
	else {
		pauseButton->View();
	}
}

ThroughPause::~ThroughPause() {
	delete pauseButton;
	delete blackBox;
	delete speedPop;
}