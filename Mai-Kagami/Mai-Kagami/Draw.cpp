#include "Draw.h"

//�F�w��
Color::Color(const char *color) {
	ChangeColor(color);
}

//�F�擾
int Color::Get() {
	return c;
}

void Color::ChangeColor(const char *color) {
	if (!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //���F
	else if (!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //�F
	else if (!strcmp(color, "Black"))
		c = GetColor(0, 0, 0); //���F
	else if (!strcmp(color, "Yellow"))
		c = GetColor(255, 255, 0); //���F
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

// �A�j���[�V�����p�p�����[�^�Z�b�g Jaity
void Pos::SetPosAnimation(float _target_x, float _target_y, MyTime _duration, int _ease) {
	if (GetTime() != 0)
		return;
	default_x = GetX() * SIZE_RATE;
	default_y = GetY() * SIZE_RATE;
	target_x = _target_x;
	target_y = _target_y;
	SetRate(_duration, _ease);
	//printfDx("Set: %f %f\n", default_x, default_y);
	//printfDx("Set: %f %f\n", target_x, target_y);
}


// �A�j���[�V�����X�V Jaity
void Pos::Update() {
	double r = UpdateRate();
	float nx = default_x + (target_x - default_x) * r;
	float ny = default_y + (target_y - default_y) * r;
	//printfDx("Update: %f %f \n", default_x, default_y);
	//printfDx("Update: %f %f\n", GetX(), GetY());
	ChangePos(nx, ny);
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