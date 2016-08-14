#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	touch = new Touch();
	scene = START; //�V�[��������
	font = new Font();
	songs = new Songs(font); //�Ȉꗗ�쐬
	top = new Top(font);
	songSelect = new SongSelect(font, touch, songs);
	throughMain = new ThroughMain(font, touch, songs);
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
	}

	top->Update(scene); //�g�b�v��ʌv�Z
	songSelect->Update(scene); //�ȑI����ʌv�Z
	throughMain->Update(scene); //�ʂ����K��ʌv�Z
}

//�S�̂̕`��
void MaiKagami::View() {
	top->View(); //�g�b�v��ʕ\��
	songSelect->View(); //�ȑI����ʕ\��
	throughMain->View();
}