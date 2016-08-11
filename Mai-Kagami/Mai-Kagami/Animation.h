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
protected:
	double UpdateRate();
	void SetRate(MyTime, int);
	void SetTime(MyTime);
	enum {
		LINER,
		EASE
	};
private:
	MyTime t = 0;		// �A�j���[�V�����̌��ݎ���
	MyTime duration;	// �A�j���[�V�������쎞��
	int ease = LINER;	// �A�j���[�V�������
};


#endif