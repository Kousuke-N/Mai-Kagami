#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"

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
	Song(const int id, const char *title, const char *artist, const char *folder);
	char *GetSongTitle(); //�Ȗ��擾
	char *GetSongArtist(); //�A�[�e�B�X�g�擾
	int GetNow(); //���݂̈ʒuID���擾
	void SetNow(const int n); //�ʒuID���Z�b�g
	void ChangeSpeed(int num); //����̍Đ����x�ύX
	void LoadPart(); //�p�[�g��񃍁[�h
	SongPart *GetPart(int num); //�p�[�g���擾
	int GetPartNum(); //�p�[�g���擾
	MyDrawGraph *coverGraph; //�J�o�[�摜
	MyDrawMovie *danceMovie; //����
protected:
	char music[256], title[256], artist[256]; //���y�t�@�C���A�^�C�g���A�A�[�e�B�X�g��
	char folder[256];
private:
	int id, *n, songPartNum; //ID�A���݂̔ԍ�, �Ȑ�
	SongPart *songPart[256];
};

#endif