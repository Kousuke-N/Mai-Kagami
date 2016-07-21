#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //�V�[��������
}

void MaiKagami::View() {
	//�v�Z
	switch (scene) {
	case TOP:
		scene = top.Update();
		break;
	case LOGIN:
		login.Update();
//		scene = songSelect.Load();
		break;
	}

	//�`��
	switch (scene) {
	case TOP:
		top.View();
		break;
	case LOGIN:
		login.View();
		break;
	case SONG_SELECT:
		break;
	}
}