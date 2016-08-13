#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"

//��ʒ�`
class Scene {
public:
	int Update(const int scene); //�X�V
	void View(); //�\��
protected:
	void Load(); //���[�h
	void Delete(); //�폜
private:
	virtual void ContentLoad() = 0;
	virtual void ContentView() = 0;
	virtual int ContentUpdate() = 0;
	virtual void ContentDelete() = 0;
	int loadFlag = 0; //���[�h�m�F�p�i0�F�����[�h�A1�F���[�h���A2�F���[�h�����j
};

#endif