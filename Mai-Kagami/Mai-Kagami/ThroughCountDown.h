#ifndef __THROUGHCOUNTDOWN_H_INCLUDED__
#define __THROUGHCOUNTDOWN_H_INCLUDED__

#include "DxLib.h"
#include "Songs.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "Touch.h"
#include "KinectDistance.h"

//�J�E���g�_�E����ʗp�Đ��O�p�`
class PlayTriangle : public MyDrawTriangle {
public:
	PlayTriangle(const float x, const float y);
};


//�J�E���g�_�E�����
class ThroughCountDown : public	SubScene {
public:
	ThroughCountDown(Font *font);
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughCountDown();
private:
	int count; //�J�E���^
	BlackBox *blackBox;
	MyDrawText *text;
	MyDrawCircle *circle;
	MyDrawCircleGauge *countCircle1;
	MyDrawCircle *countCircle2;
	PlayTriangle *playTriangle;
	const int max = 120;
};

#endif