#include "TopMain.h"

//�g�b�v��ʃR���X�g���N�^
Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
	topLogo = new TopLogo(HEIGHT / 3); //���S������
	topTouchMessage = new TopTouchMessage(f, HEIGHT * 0.42); //NFC�^�b�`���b�Z�[�W������
	topTouchButton = new TopTouchButton(f); //NFC�^�b�`�{�^��������
}

//�g�b�v��ʏ�����
void Top::Load() {
	StopMusic();

	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		topLogo->Load();
		topTouchMessage->Init();
		nfc.Init();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//�g�b�v��ʌv�Z
int Top::Update() {
	Load();
	if (loadFlag == 2) {
		topTouchMessage->Update(); //NFC�^�b�`���b�Z�[�W�v�Z
		if (nfc.GetId() != 0) {
			Delete();
			return SONG_SELECT;
		}
	}
	return TOP;
}

//�g�b�v��ʕ\��
void Top::View() {
	if (loadFlag == 2) {
		topLogo->View(); //���S�\��
		topTouchMessage->View(); //NFC�^�b�`���b�Z�[�W�\��
		topTouchButton->View(); //NFC�^�b�`�{�^���\��}
	}
}

void Top::Delete() {
	loadFlag = 0;
	topLogo->Release();
}

Top::~Top() {
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}