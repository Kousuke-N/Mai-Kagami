#include "DrawObject.h"

//円初期化（塗りつぶしあり）
//MyDrawCircle(x座標、y座標、半径、色)　※色は省略可能、省略した場合青色
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = 0;
}

//円初期化（塗りつぶしなし）
//MyDrawCircle(x座標、y座標、半径、線の太さ、色)　※色は省略可能、省略した場合青色
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//円表示
void  MyDrawCircle::ContentView() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(x, y, r, 100, Color::Get(), flag, w);
}

//角度付きの円初期化(塗りつぶしなし)
//MyDrawCircleGauge(x座標、y座標、半径、角度（％指定）、線の太さ、色)　※色は省略可能、省略した場合青色
MyDrawCircleGauge::MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName) 
	:MyDrawCircle(0, 0, width, colorName), Pos(x, y){
	r = radius / SIZE_RATE;
	ChangeDegree(degree); //角度を％からラジアンに変更
}

//角度付きの円描画
void MyDrawCircleGauge::ContentView() {
	for (double i = 0; i < rad; i += 0.02) {
		float xx = (Pos::x + r * sin(i)) * SIZE_RATE;
		float yy = (Pos::y - r * cos(i)) * SIZE_RATE;
		MyDrawCircle::ChangePos(xx, yy);
		MyDrawCircle::ContentView();
	}
	MyDrawCircle::ChangePos(GetEndX() * SIZE_RATE, GetEndY() * SIZE_RATE);
	MyDrawCircle::ContentView();
}

//角度付きの円　角度を％からラジアンに変更して保存
void MyDrawCircleGauge::ChangeDegree(const double degree) {
	rad = 2 * M_PI * degree / 100;
}

//角度付きの円　最終X座標を取得
float  MyDrawCircleGauge::GetEndX() {
	return Pos::x + r * sin(rad);
}

//角度付きの円　最終Y座標を取得
float  MyDrawCircleGauge::GetEndY() {
	return Pos::y - r * cos(rad);
}

//線初期化（座標指定なし、あとで指定する場合）
//MyDrawLine(長さ、色)　※色は省略可能、省略した場合青色
MyDrawLine::MyDrawLine(const float width, const char *colorName)
	: Color(colorName) {}

//線初期化（座標指定あり）
//MyDrawLine(始点x座標、始点y座標、終点x座標、終点y座標、長さ、色)　※色は省略可能、省略した場合青色
MyDrawLine::MyDrawLine(const float x1, const float y1, const float x2, const float y2, const float width, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2);
	w = width / SIZE_RATE;
}

//線表示
void MyDrawLine::ContentView() {
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}

//線の座標指定
void MyDrawLine::ChangePos(const float x1, const float y1, const float x2, const float y2) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
}

//三角形初期化
MyDrawTriangle::MyDrawTriangle(const char *colorName) 
	: Color(colorName) {}

//三角形初期化
//MyDrawTriangle(点１x座標、点１y座標、点２x座標、点２y座標、点３x座標、点３y座標、長さ、色)　※色は省略可能、省略した場合青色
MyDrawTriangle::MyDrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//三角形表示
void MyDrawTriangle::ContentView() {
	DrawTriangleAA(x1, y1, x2, y2, x3, y3, Color::Get(), TRUE);
}

//三角形 座標指定
void MyDrawTriangle::ChangePos(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
	this->x3 = x3 / SIZE_RATE;
	this->y3 = y3 / SIZE_RATE;
}

//正三角形初期化
//MyDrawTriangle2(x座標、y座標、一辺の長さ、方向、色)　※色は省略可能、省略した場合青色
//方向（０：上向き、１：下向き、２：左向き）
MyDrawTriangle2::MyDrawTriangle2(const float x, const float y, const float width, const int direction, const char *colorName)
	: MyDrawTriangle(colorName) {
	w = width;
	d = direction;

	float x1, x2, x3, y1, y2, y3;
	float a = w * sqrt(3) / 4;

	x1 = x2 = x3 = x;
	y1 = y2 = y3 = y;

	switch (d)
	{
	case 0:
		x2 -= w / 2; x3 += w / 2;
		y1 -= a; y2 += a; y3 += a;
		break;
	case 1:
		x2 -= w / 2; x3 += w / 2;
		y1 += a; y2 -= a; y3 -= a;
		break;
	case 2:
		y2 -= w / 2; y3 += w / 2;
		x1 += a; x2 -= a; x3 -= a;
		break;
	}

	ChangePos(x1, y1, x2, y2, x3, y3);
}

//四角形初期化(塗りつぶしあり)
//MyDrawBox(x座標、y座標、横の長さ、縦の長さ、色)　※色は省略可能、省略した場合白色
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = 0;
}

//四角形初期化（塗りつぶしなし）
//MyDrawBox(x座標、y座標、横の長さ、縦の長さ、線の太さ、色)　※色は省略可能、省略した場合青色
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = line / SIZE_RATE;
}

//四角形表示
void  MyDrawBox::ContentView() {
	boolean flag = TRUE;
	if (l != 0)
		flag = FALSE;
	float x1 = x - w / 2;
	float y1 = y - h / 2;
	float x2 = x + w / 2;
	float y2 = y + h / 2;

	DrawBoxAA(x1, y1, x2, y2, Color::Get(), flag, l);
}

//四角形サイズ変更
void MyDrawBox::ChangeSize(const float width, const float height) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
}

float MyDrawBox::GetWidth() {
	return w * SIZE_RATE;
}
float MyDrawBox::GetHeight() {
	return h * SIZE_RATE;
}

//MyPolygon(頂点のx座標,頂点のy座標,頂点の数,色)
MyDrawPolygon::MyDrawPolygon(const float x[], const float y[], int vertexNum, char* colorName) 
	:Color(colorName), Draw(){
	float xx[100] = { 0 }, yy[100] = { 0 };
	//x[]をコピー
	for (int i = 0; i < vertexNum; i++) {
		xx[i] = x[i]; yy[i] = y[i];
	}

	//三角形の座標､非三角形の座標
	float tri_x[3], tri_y[3], ntri_x[97], ntri_y[97];
	int j = 0;
	//while (vertexNum > 0) {
		int i = 0;
		//図形の方向を記録する変数
		int oldDirection = 0, newDirection = 0;
		//最も原点から遠い頂点
		int farthestVertex = FindFarthestVertex(xx, yy, vertexNum);
		do {
			//三角形を構成する頂点とそれ以外の頂点を分類
			ClassifyArray(xx, yy,  farthestVertex++, vertexNum, tri_x, tri_y, ntri_x, ntri_y);

			//三角形の向きを記録しそれを比較
			oldDirection = newDirection;
			newDirection = CheckGraphDirction(tri_x, tri_y);
			if (i > 1 && oldDirection * newDirection < 0) {
				continue;
			}
		} while (!CheckNoPointInGraph(ntri_x, ntri_y, tri_x, tri_y, vertexNum - 3));

		triangle[j] = new MyDrawTriangle(tri_x[0], tri_y[0], tri_x[1], tri_y[1], tri_x[2], tri_y[2]);
		triangleNum++;	j++;
		//三角形の頂点を除く配列の作成
		printfDx("%d", xx);
		//while (++(xx + farthestVertex) < 0)
		//	*(ptr - 1) = *ptr;
	//}
}

//座標を三角形を構成する点とそうでない点に分類する
//注意!vertexNumはすべての頂点の数
//(x座標,y座標,三角形の頂点の要素番号,頂点の数,三角形の頂点のx座標を入れる配列,三角形の頂点のy座標を入れる配列,それ以外のx座標を入れる配列,それ以外のy座標を入れる配列)
void MyDrawPolygon::ClassifyArray(const float x[], const float y[], int triangleVertex, int vertexNum, float tri_x[], float tri_y[], float ntri_x[], float ntri_y[]) {
	//三角形を構成する点の要素番号
	int vertexMakingTriangle[3] = { (triangleVertex - 2 + vertexNum) % vertexNum,
		(triangleVertex - 1 + vertexNum) % vertexNum,
		(triangleVertex + vertexNum) % vertexNum };
	//三角形を構成する点を含まない配列を作成
	float xx[100] = { 0 }, yy[100] = { 0 };
	int n = 0;
	for (int i = 0; i < vertexNum + 3; i++) {
		if (i == vertexMakingTriangle[0] || i == vertexMakingTriangle[1] || i == vertexMakingTriangle[2]) {
			tri_x[i - n] = x[i];
			tri_y[i - n] = y[i];
			printfDx("%f %f\n", x[i], y[i]);
			continue;
		}
		ntri_x[n] = x[i];	ntri_y[n] = y[i];
		n++;
	}
}

//原点から一番遠い頂点を探す
//返り値は1番遠い頂点の要素数
int MyDrawPolygon::FindFarthestVertex(const float x[], const float y[], int vertexNum) {
	int farthestVertexNum = 0;	//一番遠い頂点の番号
	float farthestDistanse = 0;	//一番遠い頂点との距離
	float distanse = 0;			//距離
	for (int i = 0; i < vertexNum; i++) {
		distanse = pow(x[i] * x[i] + y[i] * y[i], 0.5);
		if (distanse> farthestDistanse) {
			farthestDistanse = distanse;
			farthestVertexNum = i + 1;
		}
	}
	return farthestVertexNum;
}

//(x座標,y座標,三角形のを構成する点の真ん中の点の番号,頂点の数)
//x座標、y座標については三角形を構成する点も含む
//注意!vertexNumは三角形を構成しない頂点の数
//三角形の中に点がなければtrueあればfalse
bool MyDrawPolygon::CheckNoPointInGraph(const float ntri_x[], const float ntri_y[], const float tri_x[], const float tri_y[], int vertexNum) {
	//三角形の中に点がないか調べる
	int temp[3] = { 0 };
	for (int i = 0; i < vertexNum; i++) {
		temp[0] = (ntri_x[i] - tri_x[0]) * (tri_y[1] - tri_y[0]) - (ntri_y[i] - tri_y[0]) * (tri_x[1] - tri_x[0]);
		temp[1] = (ntri_x[i] - tri_x[1]) * (tri_y[2] - tri_y[1]) - (ntri_y[i] - tri_y[1]) * (tri_x[2] - tri_x[1]);
		temp[2] = (ntri_x[i] - tri_x[2]) * (tri_y[0] - tri_y[2]) - (ntri_y[i] - tri_y[2]) * (tri_x[0] - tri_x[2]);
		if ((temp[0] > 0 && temp[1] > 0 && temp[2] > 0) || (temp[0] < 0 && temp[1] < 0 && temp[2] < 0)){
			return false;
		}
	}
	return true;
}

//グラフの向きを1,0,-1のいずれかの値で返します
int MyDrawPolygon::CheckGraphDirction(const float tri_x[], const float tri_y[]) {
	float temp = (tri_x[2] - tri_x[0]) * (tri_y[1] - tri_y[0]) - (tri_y[2] - tri_y[0]) * (tri_x[1] - tri_x[0]);
	return temp == 0 ? temp :
		    temp < 0 ? -1 : 1;
}

void MyDrawPolygon::ContentView() {
	for (int i = 0; i < triangleNum; i++) {
		triangle[i]->View();
	}
}

//進捗バー初期化
MyDrawBar::MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName)
	:MyDrawBox(x + width / 2, y, width, height, colorName) {
	MyDrawBar::x = x;
	MyDrawBar::y = y;
}

//進捗バーサイズ変更
void MyDrawBar::ChangeSize(const float width, const float height) {
	MyDrawBox::ChangeSize(width, height);
	ChangePos(x + width / 2, y);
}