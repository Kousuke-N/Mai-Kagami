#include "Animation.h"
#include <math.h>
#define PI 3.1415926535897932

// �A�j���[�V�����̐i�s������Ԃ�
// �I������, �^�C�v, �x��
double Animation::ProgressRate(MyTime end, int ease = LINER, MyTime delay = 0) {
	double r, rate;
	r = (double)(t - delay) / (end - delay);
	switch (ease) {
	EASE:
		rate = (1 - cos(r * PI)) / 2;
	LINER: default:
		rate = r;
		break;
	}
	t = ++t % (end + delay);
	return rate;
}

// �A�j���[�V������~�E���Z�b�g
void Animation::Stop() {
	t = 0;
}