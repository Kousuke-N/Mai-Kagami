#include "Top.h"

//NFC�^�b�`���b�Z�[�W�R���X�g���N�^
TopTouchMessage::TopTouchMessage(Font *font) {
	char *str = "-�J�[�h���^�b�`���Ă�������-"; //�\��������
	myDrawText = new MyDrawText(font, str, WIDTH * 0.5, HEIGHT * 0.41, 1, 46);
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
	myDrawText->Draw(); //�����\��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

//NFC�^�b�`���b�Z�[�W�f�X�g���N�^
TopTouchMessage::~TopTouchMessage() {
	delete myDrawText;
}

//NFC�^�b�`�{�^���R���X�g���N�^
TopTouchButton::TopTouchButton(Font *font) {
	char *str = "������\n�^�b�`�I"; //�\��������
	myDrawCircle = new MyDrawCircle(WIDTH, NFC_POS, WIDTH / 12);
	myDrawText = new MyDrawText(font, str, WIDTH * 0.92, NFC_POS - HEIGHT * 0.028, 2, 40);
}

//NFC�^�b�`�{�^���\��
void TopTouchButton::View() {
	myDrawCircle->Draw(); //�~�\��
	myDrawText->Draw(); //�e�L�X�g�\��
}

//NFC�^�b�`���b�Z�[�W�f�X�g���N�^
TopTouchButton::~TopTouchButton() {
	delete myDrawText;
}

Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
}

//�g�b�v��ʏ�����
boolean Top::Load() {
	StopMusic();
	if (loadFlag == 0) {
		myDrawGraph = new MyDrawGraph(WIDTH / 2, HEIGHT / 3, "img/logo.png"); //���S������
		nfc.Init();
		topTouchMessage = new TopTouchMessage(f); //NFC�^�b�`���b�Z�[�W������
		topTouchButton = new TopTouchButton(f); //NFC�^�b�`�{�^��������
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
		myDrawGraph->Draw(); //���S�\��
		topTouchMessage->View(); //NFC�^�b�`���b�Z�[�W�\��
		topTouchButton->View(); //NFC�^�b�`�{�^���\��}
	}
}

void Top::Delete() {
	loadFlag = 0;
	delete myDrawGraph;
	delete topTouchButton;
	delete topTouchMessage;
}