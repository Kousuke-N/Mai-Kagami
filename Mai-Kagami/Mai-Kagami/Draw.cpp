#include "Draw.h"

int Color::White() {
	return GetColor(255, 255, 255); //���F
}

int Color::Blue() {
	return GetColor(127, 210, 234); //�F
}

void Font::Set(int p) {
	ID = CreateFontToHandle("�V�S�V�b�N", p / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
}

int Font::Get() {
	return ID;
}