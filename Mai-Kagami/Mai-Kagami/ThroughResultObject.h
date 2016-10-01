#ifndef __THROUGHRESULTOBJECT_H_INCLUDED__
#define __THROUGHRESULTOBJECT_H_INCLUDED__

#include "Dxlib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"
#include "Song.h"

//得点バー
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

//タイミング得点バー
class TimingBar : public ScoreBar {
public:
	TimingBar(Font *font);
};

//表情得点バー
class ExpressionBar : public ScoreBar {
public:
	ExpressionBar(Font *font);
};

//コメント表示
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

//体のパーツ別採点結果表示
class ResultBody : public Draw {
public:
	ResultBody(Font *font);
	void Load(const int point[4]);
	void Delete();
	~ResultBody();
private:
	void ContentView();
	MyDrawGraph *body;
	MyDrawText *part[4];
	MyDrawText *point[4];
};

//区間別採点グラフ表示
class ResultGraph : public Draw {
public:
	ResultGraph(Font *font);
	void Load(const int *ponit, const int num, Song *song);
	void Delete();
	~ResultGraph();
private:
	void ContentView();
	void AddVertex(float x, float y);
	MyDrawText *text;
	MyDrawBox *myDrawBox;
	MyDrawTexts *scale; //目盛り
	MyDrawGraph *dot[10];	//点
	MyDrawLine *line[9]; //線
	MyDrawLine *frame[2]; //枠線
	MyDrawTextV *part[64];
	Font *font;
	const float w = WIDTH * 0.6, h = HEIGHT * 0.13;
	int pointMax = 0, partMax = 0;
	MyDrawPolygon *graph;
	float vertex_x[100] = { 0 };
	float vertex_y[100] = { 0 };
	int vertexNum;
};

#endif