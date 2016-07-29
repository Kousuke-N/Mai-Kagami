#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

//�e�L�X�g�֌W
class MyDrawText : public Color, public Draw2{
public:
	MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void View(); //�`��
	void ChangeText(char *str); //�e�L�X�g�ύX
	float GetHeight(); //�c�擾
	float GetWidth(); //���擾
private:
	int f, point; //�t�H���g���A�|�W�V�������A�t�H���g�T�C�Y
	std::string s; //����
};

//�����s�̃e�L�X�g
class MyDrawTexts : public Color, public Draw {
public:
	MyDrawTexts(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineInterval, const char *colorName = "White");
	void View();
	float GetWidth(); //���擾
	~MyDrawTexts();
private:
	MyDrawText *myDrawText[256];
	float x, y; //���W
	int l, p; //�s��, �|�W�V�������
	void CalcPos(); //�ʒu�v�Z
};

//�A���_�[���C���t���e�L�X�g
class MyDrawTextLine : public MyDrawText {
public:
	MyDrawTextLine(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName = "White");
	void View();
private:
	float x1, x2, y1, y2, w; //���W�A���̑���
};

#endif