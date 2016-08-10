#ifndef __THROUGHPAUSE_H_INCLUDED__
#define __THROUGHPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"

class ThroughPause {
public:
	ThroughPause(Font *font);
	void Update(int scene);
	void Load();
	void View();
	~ThroughPause();
private:
	boolean flag; //�|�[�Y�����ǂ����̃t���O
	CircleGraphButton *pauseButton; //�ꎞ��~�p�{�^��
	BlackBox *blackBox; //�w�i���������̎l�p�`
	MyDrawText *title;
	CircleGraphTextButton *button[4];
};

#endif