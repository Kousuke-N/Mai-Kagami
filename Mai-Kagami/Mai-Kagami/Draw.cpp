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
	x = 0; y = 0;
}

//�\���ʒu�p�N���X�R���X�g���N�^
Pos::Pos(const float x, const float y) {
	this->x = x / SIZE_RATE; this->y = y / SIZE_RATE;
}

//�\���ʒu�ύX
void Pos::ChangePos(const float x, const float y) {
	this->x = x / SIZE_RATE; this->y = y / SIZE_RATE;
}

// �A�j���[�V�����p�p�����[�^�Z�b�g Jaity
void Pos::SetPosAnimation(float target_x, float target_y, MyTime duration, Easing ease) {
	if (GetTime() != 0)
		return;
	default_x = GetX();
	default_y = GetY();
	this->target_x = target_x;
	this->target_y = target_y;
	this->ease = ease;
//	SetRate(duration, ease);
	SetDuration(duration);
	//printfDx("Set: %f %f\n", default_x, default_y);
	//printfDx("Set: %f %f\n", target_x, target_y);
}


// �A�j���[�V�����X�V Jaity
void Pos::Update() {
	double r = UpdateRate(ease);
	float nx = default_x + (target_x - default_x) * r;
	float ny = default_y + (target_y - default_y) * r;
	//printfDx("Update: %f %f \n", default_x, default_y);
	//printfDx("Update: %f %f\n", GetX(), GetY());
	ChangePos(nx, ny);
}

//x���W�擾
float Pos::GetX() {
	return x * SIZE_RATE;
}

//y���W�擾
float Pos::GetY() {
	return y * SIZE_RATE;
}

//�`��p�N���X�R���X�g���N�^
Draw::Draw(){}

//�`��p�N���X�R���X�g���N�^
Draw::Draw(const float x, const float y) : Pos(x, y) {}

//�`��
void Draw::View() {
	if (viewFlag) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha); //�����x�ݒ�
		ContentView(); //���e�\��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
	}
}

void Draw::SetViewFlag(const boolean flag) {
	viewFlag = flag;
}

//�����x�w��
void Draw::SetAlpha(const int alpha) {
	this->alpha = alpha;
}

Draw2::Draw2(const int pos) {
	p = pos;
}

Draw2::Draw2(const float x, const float y, const int pos) {
	p = pos;
	ChangePos(x, y);
}

void Draw2::ChangePos() {
	float a = 0;
	switch (p) {
	case 1:
		a -= GetWidth() / 2;
		break;
	case 2:
		a -= GetWidth();
		break;
	}

	Draw::ChangePos(xx + a, yy - GetHeight() / 2);
}

void Draw2::ChangePos(const float x, const float y) {
	xx = x;
	yy = y;
	Draw2::ChangePos();
}

float Draw2::GetX() {
	return xx;
}

float Draw2::GetY() {
	return yy;
}