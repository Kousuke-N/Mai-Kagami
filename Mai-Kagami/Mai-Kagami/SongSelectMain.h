#ifndef __SONGSELECTMAIN_H_INCLUDED__
#define __SONGSELECTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "ModeSelect.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "Font.h"
#include "SongSelectCommon.h"
#include "SongSelect.h"
#include "SongSelectDefine.h"
#include "ThroughOption.h"
#include "Scene.h"

//�ȑI����ʊ֌W
class SongSelect : public Scene{
public:
	SongSelect(Font *font, Touch *touch, Songs *songs);
	int Switch();
	~SongSelect();
private:
	SongSelectTitle *songSelectTitle; //�ȑI����ʃ^�C�g��
	SongInformation *songInformation; //�I�𒆂̋�
	SongSelectButton *songSelectButton; //�{�^���֌W
	SongSelectPop *songSelectPop; //�I���p�|�b�v�A�b�v
	ModeSelectButton *modeSelectButton; //���[�h�I���{�^��
	ThroughOptionButton *throughOptionButton; //�ʂ����K�I�v�V�����{�^��
	Touch *touch; //�T�C�h�^�b�`�p�l��
	int scene;
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
};

#endif