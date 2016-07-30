#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //�V�[��������
	font = new Font();
	songs = new Songs(); //�Ȉꗗ�쐬
	top = new Top(font);
	songSelect = new SongSelect(font, songs);
	throughMain = new ThroughMain(font, songs);
}

//�S�̂̎Z�v
void MaiKagami::Update() {
	int now;

	do {
		now = scene;
		switch (scene) {
		case TOP:
			scene = top->Update(); //�g�b�v��ʌv�Z
			break;
		case SONG_SELECT:
			scene = songSelect->Update();
			break;
		case THROUGH:
			scene = throughMain->Update();
			break;
		}
	} while (now != scene);
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