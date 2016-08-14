#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Touch *touch, Songs *songs) {
	songSelectTitle = new SongSelectTitle(font); //�ȑI����ʃ^�C�g��������
	songSelectButton = new SongSelectButton(font, touch);
	songInformation = new SongInformation(font, songs, touch); //�I�𒆂̋ȏ�����
	songSelectPop = new SongSelectPop(font, touch);
	modeSelectButton = new ModeSelectButton(font, touch); //���[�h�I���{�^��������
	throughOptionButton = new ThroughOptionButton(font, songs); //�ʂ����K�I�v�V�����{�^��������
	SongSelect::touch = touch;
}

//�ȑI����ʃ��[�h
void SongSelect::ContentLoad() {
	songInformation->Load(); //�J�o�[�摜���[�h
	songSelectTitle->Load();
	scene = MAIN;
}

//�ȑI����ʏ�ʐ؂�ւ�
int SongSelect::Switch(const int scene) {

	switch (this->scene)
	{
	case BACK:
		this->scene = songSelectPop->Switch(this->scene);
		break;
	case MAIN:
		this->scene = songSelectButton->Switch(this->scene);
		break;
	case MODE:
		this->scene = modeSelectButton->Switch(this->scene);
		break;
	case OPTION1:
		if (touch->Get(2) == 1)
			this->scene = NEXT;
		if (touch->Get(4) == 1)
			this->scene = MODE;
		throughOptionButton->Check(touch);
	}

	if (this->scene == BACK_TOP) {
		Delete();
		return TOP;
	}

	if (this->scene == NEXT) {
		Delete();
		this->scene = MAIN;
		return THROUGH;
	}

	return SONG_SELECT;
}

//�ȑI����ʌv�Z
void SongSelect::ContentUpdate() {
	if (nowScene == SONG_SELECT) {
		Load();
		songInformation->Update(scene);
		songSelectTitle->Update(scene);
		songSelectPop->Update(scene);
		songSelectButton->Update(scene);
		modeSelectButton->Update(scene);
	}
}

//�ȑI����ʕ\��
void SongSelect::ContentView() {
	songInformation->View(); //�J�o�[�\��
	songSelectTitle->View(); //�^�C�g���\��
	songSelectPop->View(); //�I���p�|�b�v�A�b�v�\��
	songSelectButton->View(); //�ȑI���{�^���\��
	modeSelectButton->View(); //���[�h�I���{�^���\��
	switch (scene)
	{
	case OPTION1:
		throughOptionButton->View();
		break;
	}
}

void SongSelect::ContentDelete() {
	songInformation->Delete();
	songSelectTitle->Delete();
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
}