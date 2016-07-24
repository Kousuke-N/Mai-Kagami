#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //�V�[��������
	loading = new Loading();
	top = new Top();
	songSelect = new SongSelect();
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
		songSelect->View(loading);
		break;
	}
}