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
		scene = throughMain->Update();
		break;
	}

	switch (scene) {
	case TOP:
		top->Update(); //�g�b�v��ʌv�Z
		break;
	case SONG_SELECT:
		songSelect->Update(); //�ȑI����ʌv�Z
		break;
	case THROUGH:
		break;
	}
}

//�S�̂̕`��
void MaiKagami::View() {
	switch (scene) {
	case TOP:
		top->View(); //�g�b�v��ʕ\��
		break;
	case SONG_SELECT:
		songSelect->View();
		break;
	case THROUGH:
		throughMain->View();
		break;
	}
}