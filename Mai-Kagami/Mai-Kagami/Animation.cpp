#include "Animation.h"

// �A�j���[�V�����̐i�s�������X�V���Ė߂�l��
// �I������, �^�C�v, �x��
double Animation::UpdateRate() {
	double r, rate;
	if (duration)
		r = (double)t / duration;
	else
		r = 1;
	switch (ease) {
	EASE:
		rate = (1 - cos(r * M_PI)) / 2;
	LINER: default:
		rate = r;
		break;
	}
	if (t < duration)
		t++;
	return rate;
}

// �p�����[�^���
void Animation::SetRate(MyTime _duration, int _ease = LINER) {
	duration = _duration <= 0 ? 0 : _duration;
	ease = _ease;
}

// �A�j���[�V���������������ύX (������0������Ύ���������)
void Animation::SetTime(MyTime _t) {
	t = _t;
}

MyTime Animation::GetTime() {
	return t;
}

void Animation::Reset() {
	SetTime(0);
}