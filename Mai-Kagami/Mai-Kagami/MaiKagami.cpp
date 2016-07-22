#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //シーン初期化
	top.Load();
	login.Load();
}

//全体の計算と描画
void MaiKagami::View() {
	//計算
	switch (scene) {
	case TOP:
		scene = top.Update();
		break;
	case LOGIN:
		login.Update();
		scene = songSelect.Load();
		break;
	}

	//描画
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