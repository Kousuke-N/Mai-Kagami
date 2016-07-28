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
private:
	int GetWidth(); //���擾
	int f, p; //�t�H���g���A�|�W�V�������
	std::string s; //����
};

#endif