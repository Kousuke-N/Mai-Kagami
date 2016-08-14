#include "TopMain.h"

//�g�b�v��ʃR���X�g���N�^
Top::Top(Font *font) {
	f = font;
	topLogo = new TopLogo(HEIGHT / 3); //���S������
	topTouchMessage = new TopTouchMessage(f, HEIGHT * 0.42); //NFC�^�b�`���b�Z�[�W������
	topTouchButton = new TopTouchButton(f); //NFC�^�b�`�{�^��������
}

//�g�b�v��ʏ�����
void Top::ContentLoad() {
	StopMusic();
	topLogo->Load();
	topTouchMessage->Init();
	nfc.Init();
}

//��ʂ̐؂�ւ�
int Top::Switch(const int scene) {
	if (nfc.GetId() != 0) {
		Delete();
		return SONG_SELECT;
	}
	return TOP;
}


//�g�b�v��ʌv�Z
void Top::ContentUpdate() {
	topTouchMessage->Update(); //NFC�^�b�`���b�Z�[�W�v�Z
}

//�g�b�v��ʕ\��
void Top::ContentView() {
	topLogo->View(); //���S�\��
	topTouchMessage->View(); //NFC�^�b�`���b�Z�[�W�\��
	topTouchButton->View(); //NFC�^�b�`�{�^���\��}
}

void Top::ContentDelete() {
	topLogo->Release();
}

Top::~Top() {
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}