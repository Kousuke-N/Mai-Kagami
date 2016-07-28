#ifndef __DRAWGRAPH_H_INCLUDED__
#define __DRAWGRAPH_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"

//�摜�֌W
class MyDrawGraph {
public:
	MyDrawGraph(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	~MyDrawGraph();
private:
	ViewPos *viewPos;
	int handle;
	double ex;
};

//����֌W
class MyDrawMovie {
public:
	MyDrawMovie(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void Stop();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	void ChangeSpeed(double speed);
	~MyDrawMovie();
private:
	ViewPos *viewPos;
	int handle; //����̃n���h��
	double ex; //����̃T�C�Y
};

#endif