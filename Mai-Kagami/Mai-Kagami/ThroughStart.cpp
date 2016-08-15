#include "ThroughStart.h"

ThroughStart::ThroughStart(Font *f) {
	blackBox = new BlackBox();
	myDrawGraph = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.45, "img/start.png");
	myDrawGraph->Load();
	wait = new MyDrawText(f, "�������c", WIDTH * 0.5, HEIGHT * 0.3, 1, 40);
	caution = new MyDrawText(f, "�{�̂���2���[�g���ȏ㗣��Ă�������", WIDTH * 0.5, HEIGHT * 0.67, 1, 46, "Blue");
	annotation = new MyDrawTexts(f, "��2���[�g���ȓ��ɓ����\n�����I�ɋȂ��ꎞ��~���܂�", WIDTH * 0.5, HEIGHT * 0.75, 1, 36, 20);
	flag = TRUE;
}

void ThroughStart::ContentUpdate() {
	switch (nowScene)
	{
	case THROUGH_START:
		viewFlag = TRUE;
		break;
	case THROUGH_PLAY:
		wait->ChangeText("�ꎞ��~��");
		flag = FALSE;
	default:
		viewFlag = FALSE;
		break;
	}
}

void ThroughStart::ContentView() {
	blackBox->View();
	myDrawGraph->View();
	wait->View();
	caution->View();
	if(flag)
		annotation->View();
}

ThroughStart::~ThroughStart() {
	delete myDrawGraph;
	delete wait;
	delete caution;
	delete annotation;
	delete blackBox;
}