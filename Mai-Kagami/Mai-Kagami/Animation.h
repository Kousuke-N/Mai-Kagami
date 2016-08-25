#ifndef __ANIMATION_H_INCLUDED__
#define __ANIMATION_H_INCLUDED__

#include "Animation.h"
#define _USE_MATH_DEFINES  // �~����M_PI���g������
#include <math.h>
#include "DxLib.h"

typedef unsigned long MyTime;

class Animation {
public:
	MyTime GetTime();
	void Reset();
	enum {
		LINER,		// ���`
		SINE,		// �����g(�x���x)
		SINE_2,		// �����g(���x)
		SINE_3,		// �����g(�x��)
		QUAD,		// 2����
		LINER_QUAD,	// 1��=>2��
		QUAD_LINER,	// 2��=>1��
	};
protected:
	double UpdateRate();
	void SetRate(MyTime, int);
	void SetTime(MyTime);
private:
	MyTime t = 0;		// �A�j���[�V�����̌��ݎ���
	MyTime duration;	// �A�j���[�V�������쎞��
	int ease = LINER;	// �A�j���[�V�������
};


#endif