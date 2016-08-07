#ifndef __BUTTON_H_INCLUDED__
#define __BUTTON_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawObject.h"

#define BUTTON_POS HEIGHT * 0.5
#define BUTTON_INTERVAL HEIGHT * 0.05

//�{�^���֌W
class Button : public Draw {
public:
	Button(const int num);
	virtual void View() = 0; //�\���p�֐�
protected:
	MyDrawText *text; //�{�^���̕���
};

//�O�p�`�̃{�^��
class TriangleButton : public Button {
public:
	TriangleButton(Font *font, const char *str, const int direction, const int num, char *colorName = "Blue");
	void View();
	~TriangleButton();
private:
	MyDrawTriangle *myDrawTriangle;
};

//�������t���O�p�`�̃{�^��
class TriangleButton2 : public Button {
public:
	TriangleButton2(Font *font, const char *title, const char *str, const int direction, const int num, const float x, const char *colorName);
	void View();
	~TriangleButton2();
private:
	MyDrawTexts *descriptionText;
	MyDrawTriangle *myDrawTriangle;
	MyDrawBox *myDrawBox;
};

//�~�̃{�^��
class CircleButton : public Button {
public:
	CircleButton(Font *font, const char *str, const int num, char *colorName = "Blue"); //�����E�񂹃{�^��
	CircleButton(Font *font, const char *str, const int num, const float x, char *colorName = "Blue"); //���������񂹃{�^��
	void View();
	~CircleButton();
private:
	MyDrawCircle *myDrawCircle;
};

//�������ۂ̒��ɂ���{�^��
class CircleButton2 : public Button {
public:
	CircleButton2(Font *font, const char *str, const int num, char *colorName = "Blue");
	void View();
	~CircleButton2();
private:
	MyDrawCircle *myDrawCircle;
};

#endif