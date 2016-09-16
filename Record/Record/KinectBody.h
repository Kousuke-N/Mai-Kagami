#ifndef __KINECTBODY_H_INCLUDED__
#define __KINECTBODY_H_INCLUDED__

#include <Kinect.h>
#include "DxLib.h"
#include "stdafx.h"

class KinectBody
{
public:
	KinectBody(IKinectSensor *m_pKinectSensor); //�R���X�g���N�^
	void Update(); //�X�V
	~KinectBody(); //�f�X�g���N�^
private:
	int *userNum;
	boolean *userFlag; //���[�U�[�̏��(TRUE:�F������Ă��� / FALSE:�F������Ă��Ȃ�)

					   // Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
};

#endif