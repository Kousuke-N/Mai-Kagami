#include "ThroughResult.h"

ThroughResult::ThroughResult(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	title = new MyDrawTextLine(font, "�̓_����", WIDTH * 0.5, HEIGHT * 0.15, 1, 60, WIDTH * 0.5, 4); //�̓_����
	circle = new MyDrawCircle(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, "WHITE"); //���F�̉~
	circle->SetAlpha(220); //�~�𔼓�����
	pointCircle = new MyDrawCircleGauge(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, 78, 6); //�F�̌�
	pointCircle2 = new MyDrawCircle(pointCircle->GetEndX() * SIZE_RATE, pointCircle->GetEndY() * SIZE_RATE, 16); //�ʂ̐�̉~
	button = new CircleButton2(font, touch, "����", 4); //���փ{�^��
	text = new MyDrawText(font, "�������_", WIDTH * 0.5, HEIGHT * 0.4, 1, 46, "White"); //�u�������_�v
	point = new MyDrawText(font, "78", WIDTH * 0.46, HEIGHT * 0.5, 1, 100, "Blue"); //�_��
	unit = new MyDrawText(font, "�_", WIDTH * 0.54, HEIGHT * 0.51, 0, 46, "White"); //�u�_�v
	last = new MyDrawText(font, "�O�� --�_", WIDTH * 0.5, HEIGHT * 0.6, 1, 36, "White"); //�O��̓_��
}

void ThroughResult::Load() {
	song = songs->GetSong(songs->GetNowSong()); //���ݑI�𒆂̋Ȃ��擾
	song->coverGraph->Load(); //�ȃJ�o�[�摜�����[�h
	song->coverGraph->ChangePos(WIDTH * 0.3, HEIGHT * 0.26); //�J�o�[�摜�̕\���ʒu�ύX
	song->drawSongTitle->ChangePos(WIDTH * 0.6, HEIGHT * 0.24); //�ȃ^�C�g���̕\���ʒu�ύX
}

ThroughResultScene ThroughResult::Switch(const ThroughResultScene scene) {
	if (button->GetTouch() == 1) //�{�^���������ꂽ��
		return THROUGH_RESULT_DETAIL; //�ڍ׃y�[�W�ɔ��
	return scene;
}

void ThroughResult::ContentUpdate() {
	if (nowScene == THROUGH_RESULT_TOP) //�V�[����THROUGH_RESULT_TOP��������
		viewFlag = TRUE; //��ʂ�\��
	else //����ȊO��
		viewFlag = FALSE; //��ʂ��\��
}

void ThroughResult::ContentView() {
	title->View(); //�^�C�g���\��
	song->coverGraph->View(); //�ȃJ�o�[�摜�\��
	song->drawSongTitle->View(); //�ȃ^�C�g���\��
	circle->View(); //���F�̉~�\��
	pointCircle->View(); //�F�̌ʂ�\��
	pointCircle2->View(); //�ʂ̐�̉~��\��
	text->View(); //�u�������_�v�\��
	point->View(); //�_����\��
	unit->View(); //�u�_�v��\��
	last->View(); //�O��̓��_��\��
	button->View(); //�{�^����\��
}

ThroughResult::~ThroughResult() {
	delete title; //�^�C�g���폜
	delete circle; //�ȃJ�o�[�摜�폜
	delete pointCircle; //�F�̌ʍ폜
	delete pointCircle2; //�ʂ̐�̉~�폜
	delete button; //�{�^�����폜
	delete text; //�u�������_�v�폜
	delete point; //�_���폜
	delete unit; //�u�_�v���폜
	delete last; //�O��̓��_�폜
}