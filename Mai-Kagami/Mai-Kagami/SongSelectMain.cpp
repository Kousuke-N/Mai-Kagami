#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font) {
	f = font;
	loadFlag = 0;
}

//�ȑI����ʃ��[�h
void SongSelect::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		songSelectTitle = new SongSelectTitle(f); //�ȑI����ʃ^�C�g��������
		songSelectButton = new SongSelectButton(f);
		songSelectCover = new SongSelectCover(f); //�I�𒆂̋ȏ�����
		songSelectPop = new SongSelectPop(f);
		modeSelectButton = new ModeSelectButton(f); //���[�h�I���{�^��������
		throughOptionButton = new ThroughOptionButton(f); //�ʂ����K�I�v�V�����{�^��������
		previewMovie = new PreviewMovie(); //�v���r���[���揉����
		touch = new Touch();
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
		songSelectCover->Update(touch, scene);
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
			if (touch->Get(4) == 1)
				scene = MODE;
		}

		if (scene == BACK_TOP) {
			Delete();
			return TOP;
		}

		songSelectTitle->Update(scene);
	}
	return SONG_SELECT;
}

//�ȑI����ʕ\��
void SongSelect::View(Loading *loading) {
	if (loadFlag == 2) {
		songSelectCover->View(scene); //�J�o�[�\��
		songSelectTitle->View(scene); //�^�C�g���\��

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
	else {
		loading->View();
	}
}

void SongSelect::Delete() {
	loadFlag = 0;
	delete songSelectCover;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
	delete touch;
}