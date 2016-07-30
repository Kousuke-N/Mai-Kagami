#ifndef __SONGSELECTMAIN_H_INCLUDED__
#define __SONGSELECTMAIN_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "ModeSelect.h"
#include "Draw.h"
#include "Touch.h"
#include "Song.h"
#include "Songs.h"
#include "Font.h"
#include "SongSelectCommon.h"
#include "SongSelect.h"
#include "SongSelectDefine.h"
#include "ThroughOption.h"

//�ȑI����ʊ֌W
class SongSelect {
public:
	SongSelect(Font *font, Songs *songs);
	int Update();
	void View();
private:
	Font *f;
	SongSelectTitle *songSelectTitle; //�ȑI����ʃ^�C�g��
	SongSelectCover *songSelectCover; //�I�𒆂̋�
	SongSelectButton *songSelectButton; //�{�^���֌W
	SongSelectPop *songSelectPop; //�I���p�|�b�v�A�b�v
	ModeSelectButton *modeSelectButton; //���[�h�I���{�^��
	ThroughOptionButton *throughOptionButton; //�ʂ����K�I�v�V�����{�^��
	Touch *touch; //�T�C�h�^�b�`�p�l��
	int scene;
	int loadFlag;
	void Load();
	void Delete();
	~SongSelect();
};

#endif