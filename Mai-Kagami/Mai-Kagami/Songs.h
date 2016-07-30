#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"

class Song {
public:
	Song(const int id, const char *title, const char *artist, const char *folder);
	char *GetSongTitle(); //�Ȗ��擾
	char *GetSongArtist(); //�A�[�e�B�X�g�擾
	int GetNow();
	void SetNow(const int n);
	void ChangeSpeed(int num);
	MyDrawGraph *coverGraph; //�J�o�[�摜
	MyDrawMovie *danceMovie; //����
protected:
	char music[256], title[256], artist[256]; //���y�t�@�C���A�^�C�g���A�A�[�e�B�X�g��
private:
	int id, *n; //ID�A���݂̔ԍ�
};

class Songs {
public:
	Songs();
	int GetSongNum(); //�Ȑ��擾
	Song *GetSong(int x);
	int GetNowSong();
private:
	Song *song[256];
	int n; //�Ȑ�
};

#endif