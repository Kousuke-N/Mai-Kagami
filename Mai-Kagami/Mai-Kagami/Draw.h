#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#include "Main.h"

//�F�֌W
class Color {
public:
	Color(const char *color);
	int Get();
private:
	int c;
};

//�\���ʒu�֌W
class ViewPos {
public :
	ViewPos(float a, float b, int pos = 0, float len = 0);
	void ChangePos(float a, float b);
	void ChangeLenth( float len);
	float GetX();
	float GetY();
private:
	float x, y;
	float xx, yy;
	int p;
};

//�\���ʒu�p�N���X
class Pos {
public:
	void ChangePos(const float x, const float y); //���W�ύX
protected:
	Pos(const float x, const float y); //������
	float GetX(); //x���W�擾
	float GetY(); //y���W�擾
private:
	float a, b;
};

//�`��p�N���X
class Draw : public Pos{
public:
	Draw(const float x, const float y);
	virtual void View() = 0; //�\�����\�b�h
};

#endif