#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "Common.h"
#include "Touch.h"
#include "Font.h"
#include "Song.h"
#include "Songs.h"
#include "SongSelectDefine.h"

//�ȑI����ʃ^�C�g��
class SongSelectTitle : public Draw {
public:
	SongSelectTitle(Font *font, const float x, const float y); //������
	void Update(int scene); //�v�Z
	void View(); //�\��
	~SongSelectTitle();
private:
	MyDrawTextLine *title;
	MyDrawText *subTitle;
	int scene;
};

//�ȑI����ʃJ�o�[�֌W
class SongSelectCover {
public:
	SongSelectCover(Font *font, Songs *songs); //������
	void Load();
	void View(int scene); //�\��
	void Update(Touch *touch, int scene);
	void Release();
	~SongSelectCover();
private:
	int n, now;
	Song2 *song[256];
	MyDrawGraph *grad[2]; //�J�o�[�摜
	MyDrawGraph *box; //�J�o�[�摜
	MyDrawBox *myDrawBox;
};

#endif