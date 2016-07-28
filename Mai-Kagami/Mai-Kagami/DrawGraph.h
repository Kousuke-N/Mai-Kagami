#ifndef __DRAWGRAPH_H_INCLUDED__
#define __DRAWGRAPH_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"

//�摜�֌W
class MyDrawGraph : public Draw{
public:
	MyDrawGraph(const float x, const float y, const char *filename, const double ExRate = 1.0); //������
	void View(); //�\��
	void ChangeEx(const double ExRate); //�{���ύX
	~MyDrawGraph();
protected:
	int handle; //�摜�p�n���h��
	double ex; //�\���{��
};

//����֌W
class MyDrawMovie : public MyDrawGraph {
public:
	MyDrawMovie(const float x, const float y, const char *filename, const double ExRate); //������
	void View(); //�\��
	void Stop(); //��~
	void ChangeSpeed(double speed); //�X�s�[�h�ύX
	~MyDrawMovie();
private:
};

#endif