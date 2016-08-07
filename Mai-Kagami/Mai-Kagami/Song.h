#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "Font.h"

//�Ȗ��A�A�[�e�B�X�g���
class DrawSongTitle : public Draw {
public:
	DrawSongTitle(Font *font, const char *title, const char *artist);
	void ChangePos(const float x, const float y);
	void View();
	~DrawSongTitle();
private:
	MyDrawTextLine *songTitle; //�Ȗ��\��
	MyDrawText *songArtist; //�A�[�e�B�X�g�\��
};

//�p�[�g���
class SongPart {
public:
	SongPart(const int flame, const char *name);
	int GetFlame(); //�t���[�����擾
	char *GetName(); //�p�[�g���擾
private:
	int flame;
	char name[256]; //����
};

class Song {
public:
	Song(Font *font, const int id, const char *title, const char *artist, const char *folder);
	int GetNow(); //���݂̈ʒuID���擾
	void SetNow(const int n); //�ʒuID���Z�b�g
	void ChangeSpeed(int num); //����̍Đ����x�ύX
	void LoadPart(); //�p�[�g��񃍁[�h
	SongPart *GetPart(int num); //�p�[�g���擾
	int GetPartNum(); //�p�[�g���擾
	DrawSongTitle *drawSongTitle; //�Ȗ��A�A�[�e�B�X�g�\��
	MyDrawGraph *coverGraph; //�J�o�[�摜
	MyDrawMovie *danceMovie; //����
protected:
	char music[256], folder[256]; //���y�t�@�C���A�t�H���_
private:
	int id, *n, songPartNum; //ID�A���݂̔ԍ�, �Ȑ�
	SongPart *songPart[256];
};

#endif