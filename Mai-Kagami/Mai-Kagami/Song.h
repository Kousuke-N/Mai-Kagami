#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include <string>
#include "DxLib.h"
#include "Draw.h"
#include "Font.h"

class Song {
public:
	Song(Font *font, char *title, char *artist, char *folder, int now);
	void Update();
	void Draw();
	void Change(int num);
	int GetNow();
	~Song();
private:
	Font *font;
	MyDrawText *songTitle;
	MyDrawText *songArtist;
	MyDrawText *songLast[2];
	MyDrawLine *myDrawLine;
	MyDrawGraph *myDrawGraph; //�J�o�[�摜
	MyDrawGraph *songCover[6]; //�J�o�[�摜
	int n;
};

#endif