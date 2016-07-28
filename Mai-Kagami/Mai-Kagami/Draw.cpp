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
Draw::Draw() :Pos(0, 0) {
}

//�`��p�N���X�R���X�g���N�^
Draw::Draw(const float x, const float y) :Pos(x, y) {
}