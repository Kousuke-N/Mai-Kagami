#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "Songs.h"
#include "Scene.h"
#include "ThroughDefine.h"
#include "Touch.h"

class ThroughResult : public SubScene {
public:
	ThroughResult(Font *font, Songs *songs, Touch *touch);
	void Load();
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~ThroughResult();
private:
	MyDrawTextLine *title; //�̓_���ʉ�ʃ^�C�g��
	MyDrawCircle *circle; //���_h�\�������̉~
	MyDrawCircleGauge *pointCircle; //���_�������p�x�w��̉~
	MyDrawCircle *pointCircle2; //���_�������~
	MyDrawText *text; //�e�L�X�g�i�������_�j
	MyDrawText *point; //���_
	MyDrawText *unit; //�P�ʁi�_�j
	MyDrawText *last; //�O��̓��_
	Button *button; //���փ{�^��
	Song *song;
	Songs *songs;
	Touch *touch;
};

#endif