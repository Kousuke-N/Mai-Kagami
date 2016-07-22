#include "Login.h"

//���O�C�����b�Z�[�W�R���X�g���N�^
void LoginMessage::Init() {
	char *str = "���O�C�����Ă��܂�"; //�\��������
	myDrawText.Init(str, WIDTH / 2, HEIGHT * 0.46, 1, 50);
}

//���O�C�����b�Z�[�W�\��
void LoginMessage::View() {
	myDrawText.Draw();
}

//���O�C���A�j���[�V�����R���X�g���N�^
void LoginAnimation::Init() {
	for(int i = 0; i < 3; i++)
		myDrawCircle[i].Init(WIDTH * 0.5 + (i - 1) * WIDTH * 0.12, HEIGHT * 0.4, WIDTH / 36);
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
	for (int i = 0; i < 3; i++) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[i]); //�����x�ݒ�
		myDrawCircle[i].Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}

//���O�C����ʃ��[�h
void Login::Load() {
	loginMessage.Init();
	loginAnimation.Init();
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