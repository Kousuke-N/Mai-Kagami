#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	touch = new Touch();
	font = new Font();
	songs = new Songs(font); //�Ȉꗗ�쐬
	top = new Top(font);
	songSelect = new SongSelect(font, touch, songs);
	throughMain = new ThroughMain(font, touch, songs);
	throughResultMain = new ThroughResultMain(font, touch, songs);
	partMain = new PartMain(font, touch, songs);
	scene = TOP;
}

//�S�̂̎Z�v
void MaiKagami::Update() {
	touch->Check();
	switch (scene) {
	case TOP:
		scene = top->Switch(scene);
		break;
	case SONG_SELECT:
		scene = songSelect->Switch(scene);
		break;
	case THROUGH:
		scene = throughMain->Switch(scene);
		break;
	case THROUGH_RESULT:
		scene = throughResultMain->Switch(scene);
		break;
	case PART:
		scene = partMain->Switch(scene);
		break;
	}

	top->Update(scene); //�g�b�v��ʌv�Z
	songSelect->Update(scene); //�ȑI����ʌv�Z
	throughMain->Update(scene); //�ʂ����K�v���C��ʌv�Z
	throughResultMain->Update(scene); //�ʂ����K���ʉ�ʌv�Z
	partMain->Update(scene); //�������K�v���C��ʌv�Z
}

//�S�̂̕`��
void MaiKagami::View() {
	top->View(); //�g�b�v��ʕ\��
	songSelect->View(); //�ȑI����ʕ\��
	throughMain->View(); //�ʂ����K�v���C��ʕ\��
	throughResultMain->View(); //�ʂ����K���ʉ�ʕ\��
	partMain->View(); //�������K�v���C��ʕ\��
}

//�f�X�g���N�^
MaiKagami::~MaiKagami() {
	delete top;
	delete songSelect;
	delete throughMain;
	delete throughResultMain;
	delete partMain;
}