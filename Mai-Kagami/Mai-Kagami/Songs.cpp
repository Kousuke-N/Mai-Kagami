#include "Songs.h"

Songs::Songs(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	int id = 0;
	while (FileRead_scanf(file, "%d,%[^,\n\r],%[^,\n\r],%[^\n\r]", &id, buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, id, buf[1], buf[2], buf[0]);
		n++;
	}
	FileRead_close(file);
}

//�Ȑ��擾
int Songs::GetSongNum() {
	return n;
}

//�Ȏ擾
Song *Songs::GetSong(int x) {
	return song[x];
}

//���ݑI������Ă���Ȏ擾
int Songs::GetNowSong() {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetNow() == 0)
			return i;
	}
	return 0;
}