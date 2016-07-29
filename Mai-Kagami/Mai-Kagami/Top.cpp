#include "Top.h"

TopLogo::TopLogo(const float y)
	: MyDrawGraph(WIDTH * 0.5, y, "img/logo.png") {
}

//NFC�^�b�`���b�Z�[�W�R���X�g���N�^
TopTouchMessage::TopTouchMessage(Font *font, const float y)
	: MyDrawText(font, "-�J�[�h���^�b�`���Ă�������-", WIDTH * 0.5, y, 1, 46) {
	t = 0;
}

//NFC�^�b�`���b�Z�[�W�v�Z
void TopTouchMessage::Update() {
	if (t > 180)
		alpha = 0;
	else if (t > 120)
		alpha = (180 - t) * 255 / 60;
	else if (t > 60)
		alpha = 255;
	else
		alpha = t * 255 / 60;
	t++;
	t %= 240;
}

//NFC�^�b�`���b�Z�[�W�\��
void TopTouchMessage::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha); //�����x�ݒ�
	MyDrawText::View(); //�����\��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

//NFC�^�b�`�{�^���R���X�g���N�^
TopTouchButton::TopTouchButton(Font *font, const float r)
	: MyDrawText(font, "������\n�^�b�`�I", WIDTH - r, NFC_POS, 2, 40)
	, MyDrawCircle(WIDTH, NFC_POS, r){
}

//NFC�^�b�`�{�^���\��
void TopTouchButton::View() {
	MyDrawCircle::View(); //�~�\��
	MyDrawText::View(); //�e�L�X�g�\��
}

Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
}

//�g�b�v��ʏ�����
boolean Top::Load() {
	StopMusic();
	if (loadFlag == 0) {
		topLogo = new TopLogo(HEIGHT / 3); //���S������
		nfc.Init();
		topTouchMessage = new TopTouchMessage(f, HEIGHT * 0.42); //NFC�^�b�`���b�Z�[�W������
		topTouchButton = new TopTouchButton(f, WIDTH / 12); //NFC�^�b�`�{�^��������
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;

	if (loadFlag == 2)
		return TRUE;
	return FALSE;
}

//�g�b�v��ʌv�Z
int Top::Update() {
	if (Load()) {
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
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}