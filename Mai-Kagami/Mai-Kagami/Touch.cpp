#include "Touch.h"

//�m�F
void Touch::Check() {
	int k = KEY_INPUT_1;
	for (int i = 0; i < 5; i++) {
		if (CheckHitKey(k++))
			key[i]++;
		else
			key[i] = 0;
	}
}

//�擾
int Touch::Get(int num) {
	return key[num];
}