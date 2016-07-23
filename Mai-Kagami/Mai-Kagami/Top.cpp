#include "Top.h"

//�g�b�v���S������
void TopLogo::Init() {
	myDrawGraph.Init(WIDTH / 2, HEIGHT / 3, "img/logo.png");
}

//�g�b�v���S�\��
void TopLogo::View() {
	myDrawGraph.Draw();
}

//NFC�^�b�`���b�Z�[�W�R���X�g���N�^
void TopTouchMessage::Init() {
	char *str = "-�J�[�h���^�b�`���Ă�������-"; //�\��������
	myDrawText.Init(str, WIDTH * 0.5, HEIGHT * 0.41, 1, 46);
}

//NFC�^�b�`���b�Z�[�W�v�Z
void TopTouchMessage::Update() {
	static int t = 0; //����
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
	myDrawText.Draw(); //�����\��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

//NFC�^�b�`�{�^���R���X�g���N�^
void TopTouchButton::Init() {
	char *str = "������\n�^�b�`�I"; //�\��������
	myDrawCircle.Init(WIDTH, NFC_POS, WIDTH / 12);
	myDrawText.Init(str, WIDTH * 0.92, NFC_POS - HEIGHT * 0.028, 2, 40);
}

//NFC�^�b�`�{�^���\��
void TopTouchButton::View() {
	myDrawCircle.Draw();
	myDrawText.Draw(); //�e�L�X�g�\��
}

//�g�b�v��ʏ�����
void Top::Load() {
	topLogo.Init(); //���S������
	topTouchMessage.Init(); //NFC�^�b�`���b�Z�[�W������
	topTouchButton.Init(); //NFC�^�b�`�{�^��������
}

//�g�b�v��ʌv�Z
int Top::Update() {
	topTouchMessage.Update(); //NFC�^�b�`���b�Z�[�W�v�Z
	if (nfc.GetId() != 0)
		return LOGIN;
	return TOP;
}

//�g�b�v��ʕ\��
void Top::View() {
	topLogo.View(); //���S�\��
	topTouchMessage.View(); //NFC�^�b�`���b�Z�[�W�\��
	topTouchButton.View(); //NFC�^�b�`�{�^���\��
}