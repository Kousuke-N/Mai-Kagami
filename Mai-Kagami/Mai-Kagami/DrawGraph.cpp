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
void MyDrawGraph::ContentView() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(x, y, ex / SIZE_RATE, 0, handle, TRUE, FALSE); //�`��
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
	speed = sp = 1.0;
}

//���揉����
MyDrawMovie::MyDrawMovie(const float x, const float y, const char *filename, const double ExRate)
	: MyDrawGraph(x, y, filename, ExRate) {
	speed = sp = 1.0;
}

//����\��
void MyDrawMovie::ContentView() {
	if (!CheckHandleASyncLoad(handle)) {
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		DrawRotaGraphF(x, y, ex / SIZE_RATE, 0, handle, TRUE, TRUE); //�`��
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}

//�w�肵���t���[���Ɉړ�
void MyDrawMovie::Seek(const int flame) {
	Stop();
	SeekMovieToGraphToFrame(handle, flame);
}

//�Đ�
void MyDrawMovie::Start() {
	if (!CheckHandleASyncLoad(handle)) {
		SetSpeed();
		if (GetNowFlame() == GetAllFlame())
			Seek();
		if(GetMovieStateToGraph(handle) == 0)
			PlayMovieToGraph(handle);
	}
}

//�Đ���~
void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

//�X�s�[�h�ύX
void MyDrawMovie::ChangeSpeed(double speed) {
	MyDrawMovie::sp = speed;
}

//�X�s�[�h�Z�b�g
void MyDrawMovie::SetSpeed() {
	if (speed != sp) {
		Stop();
		Seek();
		speed = sp;
		SetPlaySpeedRateMovieToGraph(handle, speed);
	}
}

//�X�s�[�h�擾
double MyDrawMovie::GetSpeed() {
	return sp;
}

int MyDrawMovie::GetNowFlame() {
	return TellMovieToGraphToFrame(handle);
}

int MyDrawMovie::GetAllFlame() {
	return GetMovieTotalFrameToGraph(handle) - 1;
}

MyDrawMovie::~MyDrawMovie() {
	DeleteGraph(handle);
}