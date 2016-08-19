#ifndef __PARTOPTION_H_INCLUDED__
#define __PARTOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "Font.h"
#include "Songs.h"
#include "Touch.h"
#include "SongSelectDefine.h"
#include "SeetingPop.h"
#include "Button.h"

class PartOptionButton : public SubScene {
public:
	PartOptionButton(Font *font, Songs *songs, Touch *touch);
	SongSelectScene Switch(const SongSelectScene scene);
	~PartOptionButton();
private:
	void ContentUpdate();
	void ContentView();
};


#endif