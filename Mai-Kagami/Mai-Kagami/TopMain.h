#ifndef __TOPMAIN_H_INCLUDED__
#define __TOPMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Nfc.h"
#include "Font.h"
#include "Top.h"
#include "Scene.h"
#include "ThroughResultObject.h" //�e�X�g�p

//�g�b�v��ʊ֌W
class Top : public Scene {
public:
	Top(Font *font);
	MainScene Switch(const MainScene scene);
	~Top();
private:
	Font *f;
	TopLogo *topLogo; //�g�b�v���S
	TopTouchMessage *topTouchMessage; //NFC�^�b�`���b�Z�[�W
	TopTouchButton *topTouchButton; //NFC�^�b�`�{�^��
	Nfc nfc; //NFC�Ď�
	void ContentUpdate(); //�v�Z
	void ContentView(); //�\��
	void ContentLoad();
	void ContentDelete();
	TimingBar *timingBar;
};

#endif