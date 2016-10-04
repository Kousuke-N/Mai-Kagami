#include "Sound.h"

//���ʉ����[�h
SoundEffect::SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++)
		id[i] = LoadSoundMem(path[i]);
}

//���ʉ�ID���폜
int SoundEffect::Get(int SoundType) {
	return id[SoundType];
}

SoundEffect::~SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++)
		DeleteSoundMem(id[i]);	//���ʉ����폜
}