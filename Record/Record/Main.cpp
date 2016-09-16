#include "Main.h"
#include "Kinect.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(WIDTH, HEIGHT, 32); //�E�B���h�E�T�C�Y�ݒ�
	SetBackgroundColor(0, 0, 0); //�w�i�F�ݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	SetAlwaysRunFlag(TRUE); //�o�b�N�O���E���h�ł����������s

	Kinect *kinect = new Kinect();

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		kinect->Update();
		kinect->View();
	}

	DxLib_End(); // DX���C�u�����I������

	return 0;
}