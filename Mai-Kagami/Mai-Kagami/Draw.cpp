#include "Draw.h"

//�F�w��
Color::Color(const char *color) {
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

//�\���ʒu�p�N���X�R���X�g���N�^
Pos::Pos() {
	a = 0; b = 0;
}

//�\���ʒu�p�N���X�R���X�g���N�^
Pos::Pos(const float x, const float y) {
	a = x / SIZE_RATE; b = y / SIZE_RATE;
}

//�\���ʒu�ύX
void Pos::ChangePos(const float x, const float y) {
	a = x / SIZE_RATE; b = y / SIZE_RATE;
}

//x���W�擾
float Pos::GetX() {
	return a;
}

//y���W�擾
float Pos::GetY() {
	return b;
}

//�`��p�N���X�R���X�g���N�^
Draw::Draw(){}

//�`��p�N���X�R���X�g���N�^
Draw::Draw(const float x, const float y) : Pos(x, y) {}

Draw2::Draw2(const int pos) {
	p = pos;
}

Draw2::Draw2(const float x, const float y, const int pos) {
	p = pos;
	ChangePos(x, y);
}

void Draw2::ChangePos(const float x, const float y) {
	Draw2::x = x;
	Draw2::y = y;
	float a = 0;
	switch (p) {
	case 1:
		a -= GetWidth() / 2;
		break;
	case 2:
		a -= GetWidth();
		break;
	}

	Draw::ChangePos(Draw2::x + a, Draw2::y - GetHeight() / 2);
}