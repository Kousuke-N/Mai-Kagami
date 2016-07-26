#include "SongSelect.h"

//�ȑI����ʃ^�C�g�����[�h
SongSelectTitle::SongSelectTitle(Font *font) {
	char *str = "Song Select"; //�\��������
	myDrawText = new MyDrawText(font, str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //�e�L�X�g������
	myDrawLine = new MyDrawLine(WIDTH * 0.65, HEIGHT * 0.236, 1, WIDTH * 0.4, 20); //��������
}

//�ȑI����ʃ^�C�g���\��
void SongSelectTitle::View() {
	myDrawText->Draw(); //�e�L�X�g�\��
	myDrawLine->Draw(); //���\��
}

SongSelectTitle::~SongSelectTitle() {
	delete myDrawText;
	delete myDrawLine;
}

//�ȑI����ʃJ�o�[�摜������
SongSelectCover::SongSelectCover(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	while (FileRead_scanf(file, "%[^,\n\r],%[^,\n\r],%[^\n\r]", buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, buf[1], buf[2], buf[0], n);
		n++;
	}
	FileRead_close(file);

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
}

void SongSelectCover::Update(Touch *touch) {
	if (touch->Get(0) == 1 && song[0]->GetNow() < 0) {
		for (int i = 0; i < n; i++)
			song[i]->Change(1);
	}
	if (touch->Get(2) == 1 && song[n - 1]->GetNow() > 0) {
		for (int i = 0; i < n; i++)
			song[i]->Change(-1);
	}
	for (int i = 0; i < n; i++)
		song[i]->Update();
}

//�ȑI����ʃJ�o�[�摜�\��
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box->Draw();
	for (int i = 0; i < n; i++)
		song[i]->Draw();
	for (int i = 0; i < 2; i++) {
		grad[i]->Draw();
	}
}

SongSelectCover::~SongSelectCover() {
	delete box;
	delete myDrawBox;
	for (int i = 0; i < n; i++)
		delete song[i];
	for (int i = 0; i < 2; i++) {
		delete grad[i];
	}
}

//�ȑI����ʃ{�^��������
SongSelectButton::SongSelectButton(Font *font) {
	button[0] = new Button(font, "�O�̋Ȃ�", 1, 0);
	button[1] = new Button(font, "����", 0, 1);
	button[2] = new Button(font, "���̋Ȃ�", 2, 2);
	button[3] = new Button(font, "�I��", 3, 4);
}

//�ȑI����ʃ{�^���\��
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->Draw();
}

SongSelectButton::~SongSelectButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}

SongSelectPop::SongSelectPop(Font *font) {
	myDrawBox = new MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black");
	title = new MyDrawText(font, "- �I�� -", WIDTH * 0.75, HEIGHT * 0.4, 1, 40, "Blue");
	message = new MyDrawText(font, "�{���ɏI��\n���܂����H", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	button[0] = new Button(font, "�͂�", 4, 1);
	button[1] = new Button(font, "������", 4, 2);
	flag = false;
}

int SongSelectPop::Update(Touch *touch) {
	if (flag) {
		if (touch->Get(1) == 1) {
			flag = FALSE;
			return TOP;
		}
		if (touch->Get(2) == 1) {
			flag = FALSE;
			return MAIN;
		}
		return BACK;
	}
	else {
		if (touch->Get(4)) {
			flag = TRUE;
			return BACK;
		}
		return MAIN;
	}
	return MAIN;
}

void SongSelectPop::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //�����x�ݒ�
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //�����x����
	title->Draw();
	message->Draw();
	for (int i = 0; i < 2; i++)
		button[i]->Draw();
}

SongSelectPop::~SongSelectPop() {
	delete myDrawBox;
	delete title;
	delete message;
	for (int i = 0; i < 2; i++)
		delete button[i];
}


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
		touch = new Touch();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//�ȑI����ʌv�Z
int SongSelect::Update() {
	Load();
	if (loadFlag == 2) {
		touch->Check();
		if(scene == MAIN)
			songSelectCover->Update(touch);
		scene = songSelectPop->Update(touch);

		if (scene == BACK_TOP) {
			Delete();
			return TOP;
		}

	}
	return SONG_SELECT;
}

//�ȑI����ʕ\��
void SongSelect::View(Loading *loading) {
	if (loadFlag == 2) {
		songSelectCover->View(); //�J�o�[�\��
		songSelectTitle->View(); //�^�C�g���\��

		if(scene == BACK)
			songSelectPop->View();
		else
			songSelectButton->View(); //�{�^���\��
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
	delete touch;
}