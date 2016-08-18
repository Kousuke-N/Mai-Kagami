#ifndef __THROUGHRESULTOBJECT_H_INCLUDED__
#define __THROUGHRESULTOBJECT_H_INCLUDED__

#include "Dxlib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"

//���_�o�[
class ScoreBar : public Draw {
public:
	ScoreBar(Font *font, const float y, const char *title, const char *para1, const char *para2);
	void Load(const int p);
	~ScoreBar();
private:
	void ContentView();
	MyDrawTextLine *title;
	MyDrawText *para[2];
	MyDrawBox *box[8];
	MyDrawGraph *mark;
	MyDrawText *score;
};

//�^�C�~���O���_�o�[
class TimingBar : public ScoreBar {
public:
	TimingBar(Font *font);
};

//�\��_�o�[
class ExpressionBar : public ScoreBar {
public:
	ExpressionBar(Font *font);
};

//�R�����g�\��
class ResultComment : public Draw {
public:
	ResultComment(Font *font);
	void Load(const char *str);
	~ResultComment();
private:
	void ContentView();
	MyDrawTextLine *title;
	MyDrawTexts *comment;
};

//�̂̃p�[�c�ʍ̓_���ʕ\��
class ResultBody : public Draw {
public:
	ResultBody(Font *font);
	void Load(const int point[4]);
	~ResultBody();
private:
	void ContentView();
	MyDrawGraph *body;
	MyDrawText *part[4];
	MyDrawText *point[4];
};

//��ԕʍ̓_�O���t�\��
class ResultGraph : public Draw {
public:
	ResultGraph(Font *font);
	void Load(const int *ponit, const int num);
	void Delete();
	~ResultGraph();
private:
	void ContentView();
	MyDrawBox *myDrawBox;
	MyDrawTexts *scale; //�ڐ���
	MyDrawCircle *dot[10]; //�_
	MyDrawLine *line[9]; //�_
	MyDrawLine *frame[2]; //�g��
	MyDrawTextV *part[10];
	const float w = WIDTH * 0.6, h = HEIGHT * 0.13;
	int max = 0;
};

#endif