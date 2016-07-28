#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

//�e�L�X�g�֌W
class MyDrawText : public Color, public Draw{
public:
	MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void View(); //�`��
	void ChangeText(char *str); //�e�L�X�g�ύX
protected:
	float GetHeight(); //�c�擾
private:
	float GetWidth(); //���擾
	int f, p, point; //�t�H���g���A�|�W�V�������A�t�H���g�T�C�Y
	float x, y; //���W
	std::string s; //����
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