#include "Top.h"

//�g�b�v���S�R���X�g���N�^
TopLogo::TopLogo() {
	logo = LoadGraph("img/logo.png"); // �摜�̃��[�h
}

//�g�b�v���S�\��
void TopLogo::View() {
	DrawRotaGraph(WIDTH / 2, HEIGHT / 3, WIDTH / 1080.0, 0, logo, TRUE, FALSE); //���S�̕`��
}

//NFC�^�b�`���b�Z�[�W�R���X�g���N�^
TopTouchMessage::TopTouchMessage() {
	int strLen; //������̒���

	str = "-�J�[�h���^�b�`���Ă�������-"; //�\��������
	font.Set(50); //�t�H���g�T�C�Y�Z�b�g
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	x = WIDTH / 2 - strLen / 2;
	y = HEIGHT / 2.35;
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
	Color color;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha); //�����x�ݒ�
	DrawStringToHandle(x, y, str, color.White(), font.Get()); //�����\��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

//NFC�^�b�`�{�^���R���X�g���N�^
TopTouchButton::TopTouchButton() {
	font.Set(50); //�t�H���g�T�C�Y�Z�b�g
	x = WIDTH;
	y = NFC_POS;
}

//NFC�^�b�`�{�^���\��
void TopTouchButton::View() {
	Color color;

	DrawCircleAA(x, y, WIDTH / 12, 100, color.Blue(), TRUE);
	DrawStringToHandle(x - WIDTH * 0.3, y - HEIGHT * 0.025 , "������\n�^�b�`�I", color.White(), font.Get());
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