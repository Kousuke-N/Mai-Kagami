#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "Font.h"
#include "Song.h"

class ThroughResult {
public:
	ThroughResult(Font *font);
	void Update();
	void Load(Song *song);
	void View();
	~ThroughResult();
private:
	MyDrawTextLine *title; //�̓_���ʉ�ʃ^�C�g��
	MyDrawCircle *circle; //���_�̉~
	MyDrawText *text; //�e�L�X�g�i�������_�j
	MyDrawText *point; //���_
	MyDrawText *unit; //�P�ʁi�_�j
	MyDrawText *last; //�O��̓��_
	Button *button; //���փ{�^��
	Song *song;
};

#endif