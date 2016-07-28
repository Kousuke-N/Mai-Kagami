#include "DrawGraph.h"

//�摜������
MyDrawGraph::MyDrawGraph(float a, float b, char *filename, double ExRate) {
	viewPos = new ViewPos(a, b);
	handle = LoadGraph(filename); // �摜�̃��[�h
	ex = ExRate;
}

//�摜�\��
void MyDrawGraph::Draw() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(viewPos->GetX(), viewPos->GetY(), ex / SIZE_RATE, 0, handle, TRUE, FALSE); //�`��
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

void MyDrawGraph::ChangePos(float a, float b) {
	viewPos->ChangePos(a, b);
}

void MyDrawGraph::ChangeEx(double ExRate) {
	ex = ExRate;
}

MyDrawGraph::~MyDrawGraph() {
	delete viewPos;
	DeleteGraph(handle);
}

//�摜������
MyDrawMovie::MyDrawMovie(float a, float b, char *filename, double ExRate) {
	viewPos = new ViewPos(a, b);
	handle = LoadGraph(filename); // �摜�̃��[�h
	ex = ExRate;
}

//�摜�\��
void MyDrawMovie::Draw() {
	if (!CheckHandleASyncLoad(handle)) {
		if (GetMovieStateToGraph(handle) == 0) {
			SetPlaySpeedRateMovieToGraph(handle, 1.0);
			SeekMovieToGraph(handle, 0);
			PlayMovieToGraph(handle);
		}
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		DrawRotaGraphF(viewPos->GetX(), viewPos->GetY(), ex / SIZE_RATE, 0, handle, TRUE, FALSE); //�`��
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}

void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

void MyDrawMovie::ChangePos(float a, float b) {
	viewPos->ChangePos(a, b);
}

void MyDrawMovie::ChangeEx(double ExRate) {
	ex = ExRate;
}

void MyDrawMovie::ChangeSpeed(double speed) {
	PauseMovieToGraph(handle);
	SetPlaySpeedRateMovieToGraph(handle, speed);
	SeekMovieToGraph(handle, 0);
	PlayMovieToGraph(handle);
}

MyDrawMovie::~MyDrawMovie() {
	delete viewPos;
	DeleteGraph(handle);
}