#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#include "Main.h"
#include "Animation.h"

//�F�֌W
class Color {
public:
	Color(const char *color);
	int Get();
	void ChangeColor(const char *color);
private:
	int c;
};

//�\���ʒu�p�N���X
class Pos : public Animation {
public:
	void ChangePos(const float x, const float y); //���W�ύX
	void SetPosAnimation(float target_x, float target_y, MyTime duration, int ease = LINER);  // Jaity
	void Update();	// Jaity
	float GetX(); //x���W�擾
	float GetY(); //y���W�擾
protected:
	Pos();
	Pos(const float x, const float y); //������
	float x, y;
private:
	float target_x, target_y;	// �A�j���[�V�������̖ڕW���W
	float default_x, default_y;	// �A�j���[�V�����J�n���̍��W
};

//�`��p�N���X
class Draw : public Pos {
public:
	Draw();
	Draw(const float x, const float y);
	void View();
	void SetAlpha(const int alpha = 255); //�����x�w��
	void SetViewFlag(const boolean viewFlag);
private:
	virtual void ContentView() = 0; //�\�����\�b�h
	int alpha = 255; //�����x
	boolean viewFlag = TRUE;
};

//�`��p�N���X�i�ʒu�w�肠��j
class Draw2 : public Draw {
public:
	Draw2(const int position);
	Draw2(const float x, const float y, const int pos);
	void ChangePos();
	void ChangePos(const float x, const float y);
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
private :
	float xx, yy; //���W
	int p; //�|�W�V�������
};

#endif