#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "Songs.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"

//�i���o�[
class ThroughPlayBar {
public:
	ThroughPlayBar(Font *font);
	void Load(Song *song);
	void Update();
	void View();
	~ThroughPlayBar();
private:
	Font *font;
	Song *song;
	MyDrawBar *barAll, *barNow;
	MyDrawCircle *circle[2];
	MyDrawTextV *part[10];
};

//�J�E���g�_�E����ʗp�Đ��O�p�`
class PlayTriangle : public MyDrawTriangle {
public:
	PlayTriangle(const float x, const float y);
};


//�J�E���g�_�E�����
class ThroughCountDown {
public:
	ThroughCountDown(Font *font);
	void Update();
	void View();
	boolean GetFlag();
	void SetFlag(const boolean flag);
	~ThroughCountDown();
private:
	boolean flag; //�\����\��
	int count; //�J�E���^
	BlackBox *blackBox;
	MyDrawText *text;
	MyDrawCircle *circle;
	MyDrawCircleGauge *countCircle1;
	MyDrawCircle *countCircle2;
	PlayTriangle *playTriangle;
	const int max = 120;
};

//�ʂ����K���
class ThroughPlay {
public:
	ThroughPlay(Font *font);
	void Load(Song *song);
	void View();
	void Update(int scene);
	~ThroughPlay();
private:
	Font *font;
	Song *song;
	ThroughPlayBar *throughPlayBar; //�i���o�[
	ThroughCountDown *throughCountDown; //�J�E���g�_�E�����
	int scene;
};

#endif