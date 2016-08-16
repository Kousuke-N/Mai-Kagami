#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs, Touch *touch) {
	this->touch = touch;
	speedOption = new SpeedOption(font, songs, touch);
	button[0] = new CircleButton(font, touch, "�X�^�[�g!", 2);
	button[1] = new CircleButton2(font, touch, "�߂�", 4);
}

SongSelectScene ThroughOptionButton::Switch(const SongSelectScene scene) {
	if (touch->Get(2) == 1)
		return NEXT;
	if (touch->Get(4) == 1)
		return MODE;
	return scene;
}

//���[�h�I���{�^���v�Z
void ThroughOptionButton::ContentUpdate() {
	if (nowScene == OPTION1) {
		viewFlag = TRUE;
		speedOption->Check(touch);
	}
	else {
		viewFlag = FALSE;
	}
}

//�I�v�V������ʃ{�^���\��
void ThroughOptionButton::ContentView() {
	speedOption->View();
	for(int i = 0; i < 2; i++)
		button[i]->View();
}

//�I�v�V������ʃ{�^���폜
ThroughOptionButton::~ThroughOptionButton() {
	for(int i = 0; i < 2; i++)
		delete button[i];
	delete speedOption;
}