#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs) {
	speedOption = new SpeedOption(font, songs);
	button[0] = new CircleButton(font, "�X�^�[�g!", 2);
	button[1] = new CircleButton2(font, "�߂�", 4);
}


//���[�h�I���{�^���\��
void ThroughOptionButton::View() {
	speedOption->View();
	for(int i = 0; i < 2; i++)
		button[i]->View();
}

void ThroughOptionButton::Update(Touch *touch) {
	speedOption->Update(touch);
}

//���[�h�I���폜
ThroughOptionButton::~ThroughOptionButton() {
	for(int i = 0; i < 2; i++)
		delete button[i];
	delete speedOption;
}