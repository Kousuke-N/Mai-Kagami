#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "CommonText.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "SongSelectDefine.h"

//�ȑI����ʃ^�C�g��
class SongSelectTitle {
public:
	SongSelectTitle(Font *font); //������
	void Update(int scene); //�v�Z
	void View(); //�\��
	~SongSelectTitle();
private:
	DrawTitle *title;
	DrawSubtitle *subTitle;
	int scene;
};

//�ȑI����ʃJ�o�[�֌W
class SongInformation {
public:
	SongInformation(Font *font, Songs *songs); //������
	void Load();
	void View(int scene); //�\��
	void Update(Touch *touch, int scene);
	void Release();
	~SongInformation();
private:
	int n, now;
	SongSelectCover *songCover[256];
	Songs *songs;
	SongSelectCover *nowSong;
	MyDrawGraph *grad[2]; //�J�o�[�摜
	MyDrawGraph *box; //�J�o�[�摜
	MyDrawBox *myDrawBox;
	MyDrawText *songLast[2];
};

#endif