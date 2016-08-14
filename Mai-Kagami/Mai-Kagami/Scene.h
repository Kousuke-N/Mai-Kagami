#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"

//�T�u��ʒ�`
class SubScene {
public:
	int Switch(const int scene) { return scene; }; //��ʂ̐؂�ւ�
	void Update() {}; //�X�V
	void View() {}; //�\��
	void Load() {}; //���[�h
	void Delete() {}; //�폜
};

//��ʒ�`
class Scene : public SubScene {
public:
	void Update(); //�X�V
	void View(); //�\��
protected:
	void Load(); //���[�h
	void Delete(); //�폜
private:
	virtual void ContentLoad() = 0; //���[�h�ڍ�
	virtual void ContentView() = 0; //�\���ڍ�
	virtual void ContentUpdate() = 0; //�X�V�ڍ�
	virtual void ContentDelete() = 0; //�폜�ڍ�
	int loadFlag = 0; //���[�h�m�F�p�i0�F�����[�h�A1�F���[�h���A2�F���[�h�����j
};

#endif