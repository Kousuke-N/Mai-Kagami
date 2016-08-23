#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include <Windows.h>
#include <winhttp.h>
#include <wchar.h>

#include "Song.h"
#include "DxLib.h"
#include "DrawGraph.h"
#include "Font.h"

#pragma comment (lib, "winhttp.lib")

class Songs {
public:
	Songs(Font *font);
	int GetSongNum(); //�Ȑ��擾
	Song *GetSong(int x);
	int GetNowSong();
	int LoadHistory(const char *userId); //�������[�h
private:
	Song *song[256];
	int Search(const int songId);
	int n; //�Ȑ�
};

#endif