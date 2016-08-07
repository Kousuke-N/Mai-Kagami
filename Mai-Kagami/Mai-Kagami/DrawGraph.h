#ifndef __DRAWGRAPH_H_INCLUDED__
#define __DRAWGRAPH_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include <string>

//�摜�֌W
class MyDrawGraph : public Draw{
public:
	MyDrawGraph(const char *fileName); //������
	MyDrawGraph(const float x, const float y, const char *fileName, const double ExRate = 1.0); //������
	void View(); //�\��
	void Load();
	void ChangeEx(const double ExRate); //�{���ύX
	void Release();
protected:
	std::string fileName; //�t�@�C����
	int handle; //�摜�p�n���h��
	double ex; //�\���{��
};

//����֌W
class MyDrawMovie : public MyDrawGraph {
public:
	MyDrawMovie(const char *filename); //������
	MyDrawMovie(const float x, const float y, const char *filename, const double ExRate); //������
	void View(); //�\��
	void Seek(const int flame = 0); //�w�肵���t���[���Ɉړ�
	void Start(); //�Đ�
	void Stop(); //��~
	void ChangeSpeed(double speed); //�X�s�[�h�ύX
	double GetSpeed(); //�X�s�[�h�擾
	int GetAllFlame(); //�S�̂̃t���[�����擾
	int GetNowFlame(); //���݂̃t���[�����擾
	~MyDrawMovie();
private:
	double speed;
};

#endif