#include "SeetingPop.h"

//�|�b�v�A�b�v�p�l�p�`�i���F�������S��ʁj
BlackBox::BlackBox()
	: MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black") {}

void BlackBox::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //�����x�ݒ�
	MyDrawBox::View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
}