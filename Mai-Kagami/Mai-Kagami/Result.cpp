#include "Result.h"

Result::Result(Songs *songs, User *user) {
	this->songs = songs;
	this->user = user;
}

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

//���M
void Result::Send() {
	Song *song = songs->GetSong(songs->GetNowSong());
	//��ID�̃��N�G�X�g�쐬
	char songReq[126] = { 0 };
	sprintf_s(songReq, 126, "song=%d", song->GetSongId());
	printfDx("%s\n", songReq); 
	//���[�U�[ID�̃��N�G�X�g�쐬
	char userReq[32] = { 0 };
	sprintf_s(userReq, 32, "user=%s", user->GetUserId());
	printfDx("%s\n", userReq); 
	//���ݎ����̎擾
	int temp[5] = { 0 };
	GetNowTime(temp);
	//�N�����̃��N�G�X�g�쐬
	char dateReq[32] = { 0 };
	sprintf_s(dateReq, 32, "date=%2d-%2d-%2d", temp[0], temp[1], temp[2]);
	printfDx("%s\n", dateReq);
	//�����̃��N�G�X�g�쐬
	char timeReq[16] = { 0 };
	sprintf_s(timeReq, 16, "time=%2d-%2d", temp[3], temp[4]);
	printfDx("%s\n", timeReq);
	//�������_�̃��N�G�X�g�쐬
	char totalReq[16] = { 0 };
	sprintf_s(totalReq, 16, "total=%f", this->total);
	printfDx("%s\n", totalReq);
	//��ԕʍ̓_�̃��N�G�X�g�쐬
	char partReq[64] = { 0 };
	sprintf_s(partReq, 64, "part=%d", score[0]);
	for (int i = 1, n = this->max; i < n; i++) {
		sprintf_s(partReq, 64, "%s-%d", partReq, score[i]);
	}
	printfDx("%s\n", partReq);
	//�̂̕��ʍ̓_�̃��N�G�X�g�쐬
	char bodyPoint[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		switch (point[i]) {
		case 1:bodyPoint[i] = 'A';	break;
		case 2:bodyPoint[i] = 'B';	break;
		case 3:bodyPoint[i] = 'C';	break;
		}
	}
	char bodyReq[32] = { 0 };
	sprintf_s(bodyReq, 32, "body=%c-%c-%c-%c", bodyPoint[0], bodyPoint[1], bodyPoint[2], bodyPoint[3]);
	printfDx("%s\n", bodyReq);
	//�^�C�~���O�̃��N�G�X�g�쐬
	char timingReq[16] = { 0 };
	sprintf_s(timingReq, 16, "timing=%d", timing);
	printfDx("%s\n", timingReq);
	//�\��̃��N�G�X�g�쐬
	char expressionReq[16] = { 0 };
	sprintf_s(expressionReq, 16, "expression=%d", expression);
	printfDx("%s\n", expressionReq);
	//�R�����g�̃��N�G�X�g�쐬
	char commentReq[256] = { 0 };
	sprintf_s(commentReq, 256, "comment=%s", comment);
	printfDx("%s\n", commentReq);
	Http http;
}

void Result::GetNowTime(int nowTime[]) {
	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);
	nowTime[0] = pnow->tm_year + 1900;
	nowTime[1] = pnow->tm_mon + 1;
	nowTime[2] = pnow->tm_mday;
	nowTime[3] = pnow->tm_hour;
	nowTime[4] = pnow->tm_min;
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