#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

//�e�L�X�g�֌W
class MyDrawText {
public:
	MyDrawText(Font *font, char *s, int a, int b, int pos, int point, char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void Draw(); //�`��
	void ChangeText(char *s);
	int GetWidth(); //���擾
	~MyDrawText();
private:
	int f;
	ViewPos *viewPos;
	Color *color;
	std::string str; //����
};

#endif