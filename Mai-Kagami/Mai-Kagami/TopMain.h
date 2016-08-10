#ifndef __TOPMAIN_H_INCLUDED__
#define __TOPMAIN_H_INCLUDED__

#include "Nfc.h"
#include "DxLib.h"
#include "Main.h"
#include "Font.h"
#include "Top.h"

//�g�b�v��ʊ֌W
class Top {
public:
	Top(Font *font);
	int Update(); //�v�Z
	void View(); //�\��
	~Top();
private:
	Font *f;
	TopLogo *topLogo; //�g�b�v���S
	TopTouchMessage *topTouchMessage; //NFC�^�b�`���b�Z�[�W
	TopTouchButton *topTouchButton; //NFC�^�b�`�{�^��
	Nfc nfc; //NFC�Ď�
	int loadFlag;
	void Load();
	void Delete();
};

#endif