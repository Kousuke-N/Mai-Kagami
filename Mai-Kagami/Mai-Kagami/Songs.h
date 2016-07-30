#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "DxLib.h"

class Song {
public:
	Song(const int id, const char *title, const char *artist, const char *folder);
	char *GetSongTitle(); //�Ȗ��擾
	char *GetSongArtist(); //�A�[�e�B�X�g�擾
private:
	char cover[256], music[256], movie[256], title[256], artist[256];
	int id;
};

class Songs {
public:
	Songs();
	int GetSongNum(); //�Ȑ��擾
	Song *GetSong(int x);
private:
	Song *song[256];
	int n; //�Ȑ�
};

#endif