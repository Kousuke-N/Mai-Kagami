#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Touch *touch, Songs *songs) {
	songSelectTitle = new SongSelectTitle(font); //�ȑI����ʃ^�C�g��������
	songSelectButton = new SongSelectButton(font);
	songInformation = new SongInformation(font, songs); //�I�𒆂̋ȏ�����
	songSelectPop = new SongSelectPop(font);
	modeSelectButton = new ModeSelectButton(font); //���[�h�I���{�^��������
	throughOptionButton = new ThroughOptionButton(font, songs); //�ʂ����K�I�v�V�����{�^��������
	SongSelect::touch = touch;
}

//�ȑI����ʃ��[�h
void SongSelect::ContentLoad() {
	songInformation->Load(); //�J�o�[�摜���[�h
	scene = MAIN;
}

//�ȑI����ʏ�ʐ؂�ւ�
int SongSelect::Switch(const int scene) {
	songInformation->Update(touch, this->scene);
	switch (this->scene)
	{
	case BACK:
		if (touch->Get(1) == 1)
			this->scene = BACK_TOP;
		if (touch->Get(2) == 1)
			this->scene = MAIN;
		break;
	case MAIN:
		if (touch->Get(1) == 1)
			this->scene = MODE;
		if (touch->Get(4) == 1)
			this->scene = BACK;
		break;
	case MODE:
		if (touch->Get(0) == 1)
			this->scene = OPTION1;
		if (touch->Get(4) == 1)
			this->scene = MAIN;
		break;
	case OPTION1:
		if (touch->Get(2) == 1)
			this->scene = NEXT;
		if (touch->Get(4) == 1)
			this->scene = MODE;
		throughOptionButton->Check(touch);
	}

	if (scene == BACK_TOP) {
		Delete();
		return TOP;
	}

	if (scene == NEXT) {
		Delete();
		this->scene = MAIN;
		return THROUGH;
	}
	return SONG_SELECT;
}

//�ȑI����ʌv�Z
void SongSelect::ContentUpdate() {
	songSelectTitle->Update(scene);
}

//�ȑI����ʕ\��
void SongSelect::ContentView() {
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

void SongSelect::ContentDelete() {
	songInformation->Release();
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
}