#ifndef __DRAWOBJECT_H_INCLUDED__
#define __DRAWOBJECT_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include "Main.h"
#include "Draw.h"

//円関係
class MyDrawCircle : public Draw, public Color{
public:
	MyDrawCircle(const float x, const float y, const float radius, const char *colorName = "Blue"); //円初期化（塗りつぶしあり）
	MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName = "Blue"); //円初期化（塗りつぶしなし）
	void ContentView();
private:
	float r, w; //半径、線の太さ
};

//角度付きの円(線のみ)
class MyDrawCircleGauge : public MyDrawCircle , public Pos{
public:
	MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName = "Blue");
	void ContentView();
	void ChangeDegree(const double degree);
	float GetEndX();
	float GetEndY();
private:
	float r; //半径
	double rad; //角度（ラジアン）
};

//線
class MyDrawLine : public Draw, public Color {
public:
	MyDrawLine(const float width, const char *colorName = "Blue");
	MyDrawLine(const float x1, const float y1, const float x2, const float y2, const float width, const char *colorName = "Blue");
	void ChangePos(const float x1, const float y1, const float x2, const float y2);
private:
	void ContentView();
	float x1, y1, x2, y2, w;
};

class MyDrawTriangle : public Draw, public Color {
public:
	MyDrawTriangle(const char *colorName = "Blue");
	MyDrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const char *colorName = "Blue");
	void ChangePos(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3);
private:
	void ContentView();
	float x1, y1, x2, y2, x3, y3;
};

//正三角形関係
class MyDrawTriangle2 : public MyDrawTriangle {
public:
	MyDrawTriangle2(const float x, const float y, const float width, const int direction, const char *colorName = "Blue");
private:
	int d;
	float w;
};

//四角形関係
class MyDrawBox : public Draw, public Color {
public:
	MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName = "White"); //四角形初期化（塗りつぶしあり）
	MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName = "Blue"); //四角形初期化（塗りつぶしなし）
	void ContentView();
	void ChangeSize(const float width, const float height);
	float GetWidth();
	float GetHeight();
private:
	float w, h, l; //幅、高さ、線の太さ
};

//多角形
class MyDrawPolygon : public Draw {
public:
	MyDrawPolygon(const float x[], const float y[], int vertexNum, char *colorName = "Blue");
	void ContentView();
	void Delete();
private:
	void ClassifyArray(const float x[], const float y[], int triangleVertex, int vertexNum, float tri_x[], float tri_y[], float ntri_x[], float ntri_y[]);
	int FindFarthestVertex(const float x[], const float y[], int vertexNum);
	bool CheckNoPointInGraph(const float ntri_x[], const float ntri_y[], const float tri_x[], const float tri_y[], int vertexNum);
	int CheckGraphDirction(const float tri_x[], const float tri_y[]);
	float DistancePointLine(const float line_x1, const float line_y1, const float line_x2, const float line_y2, const float pointx, const float pointy);
	MyDrawTriangle* triangle[100];	//多角形を埋める三角形
	MyDrawLine* line[300];
	int triangleNum = 0;	//三角形の数
};

//バー
class MyDrawBar : public MyDrawBox {
public:
	MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName = "White"); //四角形初期化（塗りつぶしあり）
	void ChangeSize(const float width, const float height);
private:
	float x, y; //座標
};

#endif