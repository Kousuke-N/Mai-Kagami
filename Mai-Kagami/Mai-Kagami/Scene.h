#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"

//�T�u��ʒ�`
class SubScene {
public:
	int Switch(const int scene); //��ʂ̐؂�ւ�
	void Update(const int scene); //�X�V
	void View(); //�\��
	void Load(); //���[�h
	void Delete(); //�폜
protected:
	int nowScene;
	boolean viewFlag = FALSE; //�\���p�t���O(TRUE:�\���AFALSE�F��\��)
	virtual void ContentView() = 0; //�\���ڍ�
	virtual void ContentUpdate() = 0; //�X�V�ڍ�
};

//��ʒ�`
class Scene : public SubScene {
public:
	void View(); //�\��
protected:
	void Load(); //���[�h
	void Delete(); //�폜
private:
	virtual void ContentLoad() = 0; //���[�h�ڍ�
	virtual void ContentDelete() = 0; //�폜�ڍ�
	int loadFlag = 0; //���[�h�m�F�p�i0�F�����[�h�A1�F���[�h���A2�F���[�h�����j
};

#endif