#ifndef __THROUGHPAUSE_H_INCLUDED__
#define __THROUGHPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"
#include "Touch.h"
#include "Scene.h"

//�|�[�Y�{�^�����
class ThroughPauseButton : public SubScene {
public:
	ThroughPauseButton(Touch *touch);
	void Load();
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughPauseButton();
private:
	CircleGraphButton *pauseButton; //�ꎞ��~�p�{�^��
};

//�|�[�Y���
class ThroughPauseScreen : public SubScene {
public:
	ThroughPauseScreen(Font *font, Songs *songs, Touch *touch);
	void Load();
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughPauseScreen();
private:
	Songs *songs;
	BlackBox *blackBox; //�w�i���������̎l�p�`
	MyDrawText *title;
	CircleGraphTextButton *button[4];
};

//���x�ύX���
class ThroughPauseSetting : public SpeedPop {
public:
	ThroughPauseSetting::ThroughPauseSetting(Font *font, Songs *songs, Touch *touch) : SpeedPop(font, songs, touch) {};
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
};

//�|�[�Y�֌W
class ThroughPause : public SubScene {
public:
	ThroughPause(Font *font, Songs *songs, Touch *touch);
	void Load();
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughPause();
private:
	Songs *songs;
	boolean flag; //�|�[�Y�����ǂ����̃t���O
	ThroughPauseButton *throughPauseButton; //�|�[�Y�{�^�����
	ThroughPauseScreen *throughPauseScreen; //�|�[�Y���
	ThroughPauseSetting *throughPauseSetting; //���x�ύX���
};

#endif