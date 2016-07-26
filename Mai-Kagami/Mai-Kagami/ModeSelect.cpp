#include "ModeSelect.h"

//���[�h�I��������
ModeSelectButton::ModeSelectButton(Font *font) {
	char *through = "��Ȃ�ʂ��ė��K�ł��܂��B\n���Ȃ��ɂ������X�s�[�h�ŗ��K�ł��A\n���́E�̓_���s���܂��B";
	char *part = "���K��Ԃ�ݒ肵�ďW�����ė��K�ł�\n�܂��B���K�r���ł����Ă��A�X�s�[�h\n�̕ύX�⊪���߂������R�ɂł��܂��B";
	button[0] = new Button(font, "�ʂ����K���[�h", through, 0, "Blue");
	button[1] = new Button(font, "�������K���[�h", part, 2, "Yellow");
	button[2] = new Button(font, "�߂�", 3, 4);
}

//���[�h�I���{�^���\��
void ModeSelectButton::View() {
	for (int i = 0; i < 3; i++)
		button[i]->Draw();
}

//���[�h�I���폜
ModeSelectButton::~ModeSelectButton() {
	for (int i = 0; i < 3; i++)
		delete button[i];
}