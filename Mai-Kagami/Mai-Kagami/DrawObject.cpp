#include "DrawObject.h"

//�~�������i�h��Ԃ�����j
//MyDrawCircle(x���W�Ay���W�A���a�A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = 0;
}

//�~�������i�h��Ԃ��Ȃ��j
//MyDrawCircle(x���W�Ay���W�A���a�A���̑����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//�~�\��
void  MyDrawCircle::ContentView() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(x, y, r, 100, Color::Get(), flag, w);
}

//�p�x�t���̉~������(�h��Ԃ��Ȃ�)
//MyDrawCircleGauge(x���W�Ay���W�A���a�A�p�x�i���w��j�A���̑����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawCircleGauge::MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName) 
	:MyDrawCircle(0, 0, width, colorName), Pos(x, y){
	r = radius / SIZE_RATE;
	ChangeDegree(degree); //�p�x�������烉�W�A���ɕύX
}

//�p�x�t���̉~�`��
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

//�p�x�t���̉~�@�p�x�������烉�W�A���ɕύX���ĕۑ�
void MyDrawCircleGauge::ChangeDegree(const double degree) {
	rad = 2 * M_PI * degree / 100;
}

//�p�x�t���̉~�@�ŏIX���W���擾
float  MyDrawCircleGauge::GetEndX() {
	return Pos::x + r * sin(rad);
}

//�p�x�t���̉~�@�ŏIY���W���擾
float  MyDrawCircleGauge::GetEndY() {
	return Pos::y - r * cos(rad);
}

//���������i���W�w��Ȃ��A���ƂŎw�肷��ꍇ�j
//MyDrawLine(�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawLine::MyDrawLine(const float width, const char *colorName)
	: Color(colorName) {}

//���������i���W�w�肠��j
//MyDrawLine(�n�_x���W�A�n�_y���W�A�I�_x���W�A�I�_y���W�A�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawLine::MyDrawLine(const float x1, const float y1, const float x2, const float y2, const float width, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2);
	w = width / SIZE_RATE;
}

//���\��
void MyDrawLine::ContentView() {
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}

//���̍��W�w��
void MyDrawLine::ChangePos(const float x1, const float y1, const float x2, const float y2) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
}

//�O�p�`������
MyDrawTriangle::MyDrawTriangle(const char *colorName) 
	: Color(colorName) {}

//�O�p�`������
//MyDrawTriangle(�_�Px���W�A�_�Py���W�A�_�Qx���W�A�_�Qy���W�A�_�Rx���W�A�_�Ry���W�A�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawTriangle::MyDrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//�O�p�`�\��
void MyDrawTriangle::ContentView() {
	DrawTriangleAA(x1, y1, x2, y2, x3, y3, Color::Get(), TRUE);
}

//�O�p�` ���W�w��
void MyDrawTriangle::ChangePos(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
	this->x3 = x3 / SIZE_RATE;
	this->y3 = y3 / SIZE_RATE;
}

//���O�p�`������
//MyDrawTriangle2(x���W�Ay���W�A��ӂ̒����A�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
//�����i�O�F������A�P�F�������A�Q�F�������j
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

//�l�p�`������(�h��Ԃ�����)
//MyDrawBox(x���W�Ay���W�A���̒����A�c�̒����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ���F
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = 0;
}

//�l�p�`�������i�h��Ԃ��Ȃ��j
//MyDrawBox(x���W�Ay���W�A���̒����A�c�̒����A���̑����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = line / SIZE_RATE;
}

//�l�p�`�\��
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

//�l�p�`�T�C�Y�ύX
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

//MyPolygon(���_��x���W,���_��y���W,���_�̐�,�F)
MyDrawPolygon::MyDrawPolygon(const float x[], const float y[], int vertexNum, char* colorName) 
	:Color(colorName), Draw(){
	float xx[100] = { 0 }, yy[100] = { 0 };
	//x[]���R�s�[
	for (int i = 0; i < vertexNum; i++) {
		xx[i] = x[i]; yy[i] = y[i];
	}

	//�O�p�`�̍��W���O�p�`�̍��W
	float tri_x[3], tri_y[3], ntri_x[97], ntri_y[97];
	int j = 0;
	//while (vertexNum > 0) {
		int i = 0;
		//�}�`�̕������L�^����ϐ�
		int oldDirection = 0, newDirection = 0;
		//�ł����_���牓�����_
		int farthestVertex = FindFarthestVertex(xx, yy, vertexNum);
		do {
			//�O�p�`���\�����钸�_�Ƃ���ȊO�̒��_�𕪗�
			ClassifyArray(xx, yy,  farthestVertex++, vertexNum, tri_x, tri_y, ntri_x, ntri_y);

			//�O�p�`�̌������L�^��������r
			oldDirection = newDirection;
			newDirection = CheckGraphDirction(tri_x, tri_y);
			if (i > 1 && oldDirection * newDirection < 0) {
				continue;
			}
		} while (!CheckNoPointInGraph(ntri_x, ntri_y, tri_x, tri_y, vertexNum - 3));

		triangle[j] = new MyDrawTriangle(tri_x[0], tri_y[0], tri_x[1], tri_y[1], tri_x[2], tri_y[2]);
		triangleNum++;	j++;
		//�O�p�`�̒��_�������z��̍쐬
		printfDx("%d", xx);
		//while (++(xx + farthestVertex) < 0)
		//	*(ptr - 1) = *ptr;
	//}
}

//���W���O�p�`���\������_�Ƃ����łȂ��_�ɕ��ނ���
//����!vertexNum�͂��ׂĂ̒��_�̐�
//(x���W,y���W,�O�p�`�̒��_�̗v�f�ԍ�,���_�̐�,�O�p�`�̒��_��x���W������z��,�O�p�`�̒��_��y���W������z��,����ȊO��x���W������z��,����ȊO��y���W������z��)
void MyDrawPolygon::ClassifyArray(const float x[], const float y[], int triangleVertex, int vertexNum, float tri_x[], float tri_y[], float ntri_x[], float ntri_y[]) {
	//�O�p�`���\������_�̗v�f�ԍ�
	int vertexMakingTriangle[3] = { (triangleVertex - 2 + vertexNum) % vertexNum,
		(triangleVertex - 1 + vertexNum) % vertexNum,
		(triangleVertex + vertexNum) % vertexNum };
	//�O�p�`���\������_���܂܂Ȃ��z����쐬
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

//���_�����ԉ������_��T��
//�Ԃ�l��1�ԉ������_�̗v�f��
int MyDrawPolygon::FindFarthestVertex(const float x[], const float y[], int vertexNum) {
	int farthestVertexNum = 0;	//��ԉ������_�̔ԍ�
	float farthestDistanse = 0;	//��ԉ������_�Ƃ̋���
	float distanse = 0;			//����
	for (int i = 0; i < vertexNum; i++) {
		distanse = pow(x[i] * x[i] + y[i] * y[i], 0.5);
		if (distanse> farthestDistanse) {
			farthestDistanse = distanse;
			farthestVertexNum = i + 1;
		}
	}
	return farthestVertexNum;
}

//(x���W,y���W,�O�p�`�̂��\������_�̐^�񒆂̓_�̔ԍ�,���_�̐�)
//x���W�Ay���W�ɂ��Ă͎O�p�`���\������_���܂�
//����!vertexNum�͎O�p�`���\�����Ȃ����_�̐�
//�O�p�`�̒��ɓ_���Ȃ����true�����false
bool MyDrawPolygon::CheckNoPointInGraph(const float ntri_x[], const float ntri_y[], const float tri_x[], const float tri_y[], int vertexNum) {
	//�O�p�`�̒��ɓ_���Ȃ������ׂ�
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

//�O���t�̌�����1,0,-1�̂����ꂩ�̒l�ŕԂ��܂�
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

//�i���o�[������
MyDrawBar::MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName)
	:MyDrawBox(x + width / 2, y, width, height, colorName) {
	MyDrawBar::x = x;
	MyDrawBar::y = y;
}

//�i���o�[�T�C�Y�ύX
void MyDrawBar::ChangeSize(const float width, const float height) {
	MyDrawBox::ChangeSize(width, height);
	ChangePos(x + width / 2, y);
}