#include "DrawGraph.h"


//�摜������
MyDrawGraph::MyDrawGraph(const char *fileName) {
	ex = 1.0;
	MyDrawGraph::fileName = fileName;
}
//�摜������
MyDrawGraph::MyDrawGraph(const float x, const float y, const char *fileName, const double ExRate) : Draw(x, y) {
	ex = ExRate;
	MyDrawGraph::fileName = fileName;
}

void MyDrawGraph::Load() {
	handle = LoadGraph(fileName.c_str()); // �摜�̃��[�h
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

//�摜�����
void MyDrawGraph::Release() {
	DeleteGraph(handle);
}

//���揉����
MyDrawMovie::MyDrawMovie(const char *filename) : MyDrawGraph(filename) {
	speed = 1.0;
}

//���揉����
MyDrawMovie::MyDrawMovie(const float x, const float y, const char *filename, const double ExRate)
	: MyDrawGraph(x, y, filename, ExRate) {
	speed = 1.0;
}

//����\��
void MyDrawMovie::View() {
	if (!CheckHandleASyncLoad(handle)) {
		if (GetMovieStateToGraph(handle) == 0) {
			SetPlaySpeedRateMovieToGraph(handle, speed);
			SeekMovieToGraph(handle, 0);
			PlayMovieToGraph(handle);
		}
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		DrawRotaGraphF(GetX(), GetY(), ex / SIZE_RATE, 0, handle, TRUE, TRUE); //�`��
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}

//�Đ���~
void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

//�X�s�[�h�ύX
void MyDrawMovie::ChangeSpeed(double speed) {
	MyDrawMovie::speed = speed;
	PauseMovieToGraph(handle);
}

//�X�s�[�h�擾
double MyDrawMovie::GetSpeed() {
	return speed;
}

int MyDrawMovie::GetNowFlame() {
	return TellMovieToGraphToFrame(handle);
}

int MyDrawMovie::GetAllFlame() {
	return GetMovieTotalFrameToGraph(handle);
}

MyDrawMovie::~MyDrawMovie() {
	DeleteGraph(handle);
}