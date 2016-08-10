#ifndef __THROUGHSTART_H_INCLUDED__
#define __THROUGHSTART_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"

class ThroughStart{
public:
	ThroughStart(Font *f);
	void Update(int scene);
	void View();
	~ThroughStart();
private:
	boolean flag; //annotation�\���p�t���O
	MyDrawGraph *myDrawGraph;
	MyDrawText *wait;
	MyDrawText *caution;
	MyDrawTexts *annotation;
	BlackBox *blackBox;
};

#endif