#ifndef __TOUCH_H_INCLUDED__
#define __TOUCH_H_INCLUDED__

#include "DxLib.h"

class Touch {
public:
	void Check(); //�m�F
	int Get(int num); //�擾
private:
	int key[5];
};


#endif