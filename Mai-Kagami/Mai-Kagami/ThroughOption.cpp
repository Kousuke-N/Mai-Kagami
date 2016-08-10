#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs) {
	speedOption = new SpeedOption(font, songs);
	button = new CircleButton(font, "�X�^�[�g!", 2);
}


//���[�h�I���{�^���\��
void ThroughOptionButton::View() {
	speedOption->View();
	button->View();
}

void ThroughOptionButton::Update(int scene) {
	if (scene == OPTION1)
		speedOption->Update();
}

//���[�h�I���폜
ThroughOptionButton::~ThroughOptionButton() {
	delete button;
	delete speedOption;
}