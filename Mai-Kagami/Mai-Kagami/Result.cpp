#include "Result.h"

void Result::Calc() {
	total = 64;
	strcpy(comment, "B��������T�r�ɓ����Ă���T�r�̏I���ɂ����Ă����\n�̂悤�Ɏv���܂��B�������d�_�I�ɗ��K���܂��傤�B");
	point[0] = 2;
	point[1] = 2;
	point[2] = 1;
	point[3] = 1;
	score[0] = 50;
	score[1] = 80;
	score[2] = 40;
	score[3] = 90;
	score[4] = 100;
	score[5] = 70;
	score[6] = 60;
	score[7] = 80;
	score[8] = 40;
	score[9] = 90;
	max = 10;
	timing = 2;
	expression = 4;
}

float Result::GetTotal() {
	return total;
}

//���ʕʓ��_�擾
void Result::GetPoint(int x[4]) {
	for (int i = 0; i < 4; i++)
		x[i] = point[i];
}

//�R�����g�擾
char *Result::GetComment() {
	return comment;
}

//�^�C�~���O�擾
int Result::GetTiming() {
	return timing;
}

//�\��擾
int Result::GetExpression() {
	return expression;
}

//��ԕʓ��_�擾
int Result::GetScore(int x[100]) {
	for (int i = 0; i < max; i++)
		x[i] = score[i];
	return max;
}