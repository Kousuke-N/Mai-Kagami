#include "DxLib.h"
#include "MaiKagami.h"
#include "Draw.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(WIDTH / SIZE_RATE, HEIGHT / SIZE_RATE, 32); //�E�B���h�E�T�C�Y�ݒ�
	SetBackgroundColor(0, 0, 0); //�w�i�F�ݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	MaiKagami maiKagami; //�����N���X�쐬

						 // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
		maiKagami.View(); //������ʕ\��

	DxLib_End(); // DX���C�u�����I������
	return 0;
}