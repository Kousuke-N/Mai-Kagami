#include "DrawGraph.h"

//�摜������
MyDrawGraph::MyDrawGraph(const float x, const float y, const char *filename, const double ExRate) : Draw(x, y) {
	handle = LoadGraph(filename); // �摜�̃��[�h
	ex = ExRate;
}

//�摜�\��
void MyDrawGraph::View() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(GetX(), GetY(), ex / SIZE_RATE, 0, handle, TRUE, FALSE); //�`��
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

//�傫���ύX
void MyDrawGraph::ChangeEx(const double ExRate) {
	ex = ExRate;
}

MyDrawGraph::~MyDrawGraph() {
	DeleteGraph(handle);
}

//���揉����
MyDrawMovie::MyDrawMovie(const float x, const float y, const char *filename, const double ExRate)
	: MyDrawGraph(x, y, filename, ExRate) {
}

//����\��
void MyDrawMovie::View() {
	if (!CheckHandleASyncLoad(handle)) {
		if (GetMovieStateToGraph(handle) == 0) {
			SetPlaySpeedRateMovieToGraph(handle, 1.0);
			SeekMovieToGraph(handle, 0);
			PlayMovieToGraph(handle);
		}
		MyDrawGraph::View();
	}
}

//�Đ���~
void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

//�X�s�[�h�ύX
void MyDrawMovie::ChangeSpeed(double speed) {
	PauseMovieToGraph(handle);
	SetPlaySpeedRateMovieToGraph(handle, speed);
	SeekMovieToGraph(handle, 0);
	PlayMovieToGraph(handle);
}

MyDrawMovie::~MyDrawMovie() {
	DeleteGraph(handle);
}