#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Songs *songs) {
	f = font;
	loadFlag = 0;
	songSelectTitle = new SongSelectTitle(f, WIDTH * 0.65, HEIGHT * 0.23); //�ȑI����ʃ^�C�g��������
	songSelectButton = new SongSelectButton(f);
	songInformation = new SongInformation(f, songs); //�I�𒆂̋ȏ�����
	songSelectPop = new SongSelectPop(f);
	modeSelectButton = new ModeSelectButton(f); //���[�h�I���{�^��������
	throughOptionButton = new ThroughOptionButton(f, songs); //�ʂ����K�I�v�V�����{�^��������
	touch = new Touch();
}

//�ȑI����ʃ��[�h
void SongSelect::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		songInformation->Load(); //�J�o�[�\��
		loadFlag = 1;
		scene = MAIN;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//�ȑI����ʌv�Z
int SongSelect::Update() {
	Load();
	if (loadFlag == 2) {
		touch->Check();
		songInformation->Update(touch, scene);
		switch (scene)
		{
		case BACK:
			if (touch->Get(1) == 1)
				scene = BACK_TOP;
			if (touch->Get(2) == 1)
				scene = MAIN;
			break;
		case MAIN:
			if (touch->Get(1) == 1)
				scene = MODE;
			if (touch->Get(4) == 1)
				scene = BACK;
			break;
		case MODE:
			if (touch->Get(0) == 1)
				scene = OPTION1;
			if (touch->Get(4) == 1)
				scene = MAIN;
			break;
		case OPTION1:
			if (touch->Get(2) == 1)
				scene = NEXT;
			if (touch->Get(4) == 1)
				scene = MODE;
		}

		if (scene == BACK_TOP) {
			Delete();
			return TOP;
		}
		
		if (scene == NEXT)
			return THROUGH;

		throughOptionButton->Update(touch, scene);
		songSelectTitle->Update(scene);
	}
	return SONG_SELECT;
}

//�ȑI����ʕ\��
void SongSelect::View() {
	if (loadFlag == 2) {
		songInformation->View(scene); //�J�o�[�\��
		songSelectTitle->View(); //�^�C�g���\��

		switch (scene)
		{
		case BACK:
			songSelectPop->View();
			break;
		case MAIN:
			songSelectButton->View(); //�ȑI���{�^���\��
			break;
		case MODE:
			modeSelectButton->View(); //���[�h�I���{�^���\��
			break;
		case OPTION1:
			throughOptionButton->View();
			break;
		}
	}
}

void SongSelect::Delete() {
	loadFlag = 0;
	songInformation->Release();
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
	delete touch;
}