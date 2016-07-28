#include "Draw.h"

//�F�w��
Color::Color(char *color) {
	if(!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //���F
	else if(!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //�F
	else if(!strcmp(color, "Black"))
		c = GetColor(0, 0, 0); //���F
	else if (!strcmp(color, "Yellow"))
		c = GetColor(255, 255, 0); //���F
}

//�F�擾
int Color::Get() {
	return c;
}

//�|�W�V�����w��(�E��/������/����)
ViewPos::ViewPos(float a, float b, int pos, float len) {
	p = pos;
	x = a / SIZE_RATE; y = b / SIZE_RATE;
	xx = x; yy = y;
	switch (p) {
	case 1:
		x -= len / 2;
		break;
	case 2:
		x -= len;
		break;
	}
}

void ViewPos::ChangePos(float a, float b) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
}

void ViewPos::ChangeLenth(float len) {
	x = xx; y = yy;
	switch (p) {
	case 1:
		x -= len / 2;
		break;
	case 2:
		x -= len;
		break;
	}
}

//x���W�擾
float ViewPos::GetX() {
	return x;
}

//y���W�擾
float ViewPos::GetY() {
	return y;
}