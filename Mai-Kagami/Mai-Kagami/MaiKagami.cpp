#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //�V�[��������
//	login.Load();
	top = new Top();
}

//�S�̂̌v�Z�ƕ`��
void MaiKagami::View() {
	switch (scene) {
	case TOP:
		scene = top->Update(); //�g�b�v��ʌv�Z
		top->View(); //�g�b�v��ʕ\��
		break;
/*	case LOGIN:
		login.Update();
		scene = songSelect.Load();
		login.View();
		break;
	case SONG_SELECT:
		scene = songSelect.Update();
		songSelect.View();*/
	}
}