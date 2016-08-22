#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

//����
class SongHistory {
public:
	void Set(const int history[2]); //�����Z�b�g
	void Get(int *history[2]); //�����擾
private:
	int history[2] = {-1, -1}; //��ID,
};

//���O�C��
class Login {
public:
	Login();
	void LoadHistory(const char *userId); //�������[�h
	void GetHistory(const int songId, int *history[2]); //�����擾
	~Login();
private:
	SongHistory *songHistory[256];
};

#endif