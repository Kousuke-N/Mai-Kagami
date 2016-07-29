#include "Top.h"

//�g�b�v���S
TopLogo::TopLogo(const float y)
	: MyDrawGraph(WIDTH * 0.5, y, "img/logo.png") {
}

//NFC�^�b�`���b�Z�[�W�R���X�g���N�^
TopTouchMessage::TopTouchMessage(Font *font, const float y)
	: MyDrawText(font, "-�J�[�h���^�b�`���Ă�������-", WIDTH * 0.5, y, 1, 46) {
	Init(); //������
}


//NFC�^�b�`���b�Z�[�W������
void TopTouchMessage::Init() {
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