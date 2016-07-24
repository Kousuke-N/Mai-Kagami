#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //�V�[��������
	login.Load();
}

//�S�̂̌v�Z�ƕ`��
void MaiKagami::View() {
	//�v�Z
	switch (scene) {
	case TOP:
		if(top.Load())
			scene = top.Update();
		break;
	case LOGIN:
		login.Update();
		scene = songSelect.Load();
		break;
	case SONG_SELECT:
		scene = songSelect.Update();
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
		songSelect.View();
		break;
	}
}