#include "Login.h"

//���O�C�����b�Z�[�W�R���X�g���N�^
LoginMessage::LoginMessage() {
	int strLen; //�����̒���
	str = "���O�C�����Ă��܂�"; //�\��������
	font.Set(50); //�t�H���g�T�C�Y�Z�b�g
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	x = WIDTH / 2 - strLen / 2;
	y = HEIGHT * 0.46;
}

//���O�C�����b�Z�[�W�\��
void LoginMessage::View() {
	Color color;
	DrawStringToHandle(x, y, str, color.White(), font.Get()); //�����\��
}

//���O�C���A�j���[�V�����R���X�g���N�^
LoginAnimation::LoginAnimation() {
	int strLen; //�����̒���
	x = WIDTH * 0.5;
	y = HEIGHT * 0.4;
	r = WIDTH / 36;
}

//���O�C���A�j���[�V�����v�Z
void LoginAnimation::Update() {
	static int t = 0; //����
	if (t < 60) {
		alpha[1] = 0; alpha[2] = 0;
		if (t < 30)
			alpha[0] = t * 255 / 30;
		else
			alpha[0] = 255;
	}
	else if (t < 120) {
		alpha[0] = 255; alpha[2] = 0;
		if (t < 90)
			alpha[1] = (t - 60) * 255 / 30;
		else
			alpha[1] = 255;
	}
	else if (t < 180) {
		alpha[0] = 255; alpha[1] = 255;
		if (t < 150)
			alpha[2] = (t - 120) * 255 / 30;
		else
			alpha[2] = 255;

	}
	else {
		if (t < 210) {
			alpha[0] = (210 - t) * 255 / 30;
			alpha[1] = (210 - t) * 255 / 30;
			alpha[2] = (210 - t) * 255 / 30;
		}
		else {
			alpha[0] = 0; alpha[1] = 0; alpha[2] = 0;
		}
	}
	t++;
	t %= 240;
}

//���O�C���A�j���[�V�����\��
void LoginAnimation::View() {
	Color color;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[0]); //�����x�ݒ�
	DrawCircleAA(x - WIDTH * 0.12, y, r, 100, color.Blue(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[1]); //�����x�ݒ�
	DrawCircleAA(x, y, r, 100, color.Blue(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[2]); //�����x�ݒ�
	DrawCircleAA(x + WIDTH * 0.12, y, r, 100, color.Blue(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

//���O�C����ʌv�Z
void Login::Update() {
	loginAnimation.Update(); //���O�C���A�j���[�V�����v�Z
}

//���O�C����ʕ\��
void Login::View() {
	loginMessage.View(); //���O�C�����b�Z�[�W�\��
	loginAnimation.View(); //���O�C���A�j���[�V�����\��
}