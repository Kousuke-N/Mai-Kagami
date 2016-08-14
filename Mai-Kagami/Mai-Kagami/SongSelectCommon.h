#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "CommonText.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "SongSelectDefine.h"
#include "Scene.h"

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
class SongInformation : public SubScene {
public:
	SongInformation(Font *font, Songs *songs, Touch *touch); //������
	void Load();
	void ContentView(); //�\��
	void ContentUpdate();
	void Delete();
	~SongInformation();
private:
	int n, now;
	Touch *touch;
	SongSelectCover *songCover[256];
	Songs *songs;
	SongSelectCover *nowSong;
	MyDrawGraph *grad[2]; //�J�o�[�摜
	MyDrawGraph *box; //�J�o�[�摜
	MyDrawBox *myDrawBox;
	MyDrawText *songLast[2];
};

#endif