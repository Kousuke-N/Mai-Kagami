#include "ThroughDetail.h"

ThroughFinish::ThroughFinish(Font *font, Touch *touch) {
	blackBox = new BlackBox();
	button[0] = new RecommendButton(font, touch, 0);
	button[1] = new CircleButton(font, touch, "もう一度", 1, WIDTH * 0.75, "White");
	button[2] = new CircleButton(font, touch, "部分練習", 2, WIDTH * 0.75, "White");
	button[3] = new CircleButton(font, touch, "曲選択画面", 3, WIDTH * 0.75, "White");
}

ThroughResultScene ThroughFinish::Switch(const ThroughResultScene scene) {
	if (button[0]->GetTouch() == 1)
		return THROUGH_RESULT_BACK_PART_OPTION;
	if (button[1]->GetTouch() == 1)
		return THROUGH_RESULT_BACK_PLAY;
	if (button[2]->GetTouch() == 1)
		return THROUGH_RESULT_BACK_PART_OPTION;
	if (button[3]->GetTouch() == 1)
		return THROUGH_RESULT_BACK_SONG_SELECT;
	return scene;
}

void ThroughFinish::ContentUpdate() {
	if (nowScene == THROUGH_RESULT_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughFinish::ContentView() {
	blackBox->View();
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

ThroughFinish::~ThroughFinish() {
	delete blackBox;
	for (int i = 0; i < 4; i++)
		delete button[i];
}

ThroughDetailScreen::ThroughDetailScreen(Font *font, Songs *songs, Touch *touch, Result *result) {
	this->songs = songs;
	this->result = result;
	title = new DrawTitle(font, "採点結果");
	timingBar = new TimingBar(font);
	expressionBar = new ExpressionBar(font);
	resultComment = new ResultComment(font);
	resultBody = new ResultBody(font);
	resultGraph = new ResultGraph(font);
	button = new CircleButton2(font, touch, "次へ", 4);
}

ThroughResultScene ThroughDetailScreen::Switch(const ThroughResultScene scene) {
	if (button->GetTouch() == 1)
		return THROUGH_RESULT_FINISH;
	return scene;
}

void ThroughDetailScreen::Load() {
	Song *song = songs->GetSong(songs->GetNowSong());
	int point[4];
	int score[100];
	int max = result->GetScore(score);
	timingBar->Load(result->GetTiming());
	expressionBar->Load(result->GetExpression());
	result->GetPoint(point);
	resultBody->Load(point);
	resultComment->Load(result->GetComment());
	resultGraph->Load(score, max, song);
}

void ThroughDetailScreen::ContentUpdate() {
	if (nowScene == THROUGH_RESULT_DETAIL || nowScene == THROUGH_RESULT_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughDetailScreen::ContentView() {
	title->View();
	timingBar->View();
	expressionBar->View();
	resultComment->View();
	button->View();
	resultBody->View();
	resultGraph->View();
}

void ThroughDetailScreen::Delete() {
	resultGraph->Delete();
	resultBody->Delete();
}

ThroughDetailScreen::~ThroughDetailScreen() {
	delete title;
	delete timingBar;
	delete expressionBar;
	delete resultComment;
	delete button;
	delete resultGraph;
}

ThroughDetail::ThroughDetail(Font *font, Songs *songs, Touch *touch, Result *result) {
	throughDetailScreen = new ThroughDetailScreen(font, songs, touch, result);
	throughFinish = new ThroughFinish(font, touch);
}

ThroughResultScene ThroughDetail::Switch(const ThroughResultScene scene) {
	switch (scene)
	{
	case THROUGH_RESULT_DETAIL:
		return throughDetailScreen->Switch(scene);
	case THROUGH_RESULT_FINISH:
		return throughFinish->Switch(scene);
	}
	return scene;
}

void ThroughDetail::Load() {
	throughDetailScreen->Load();
	throughFinish->Load();
}

void ThroughDetail::ContentUpdate() {
	throughFinish->Update(nowScene);
	throughDetailScreen->Update(nowScene);
	if (nowScene == THROUGH_RESULT_DETAIL || nowScene == THROUGH_RESULT_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughDetail::ContentView() {
	throughDetailScreen->View();
	throughFinish->View();
}

void ThroughDetail::Delete() {
	throughDetailScreen->Delete();
}

ThroughDetail::~ThroughDetail() {
	delete throughDetailScreen;
	delete throughFinish;
}

RecommendButton::RecommendButton(Font *font, Touch* touch, const int num)
	: Button(num, touch){
	text = new MyDrawTextLine(font, "おすすめ練習", WIDTH * 0.75, GetY() - HEIGHT * 0.015, 1, 30, WIDTH * 0.25,  3, "White");
	myDrawCircle = new MyDrawCircle(WIDTH * 0.97, GetY(), WIDTH * 0.015, 7, "White");
	textSub = new MyDrawText(font, "Bメロ〜サビ 　速度:×0.7", WIDTH * 0.75, GetY() + HEIGHT * 0.015, 1, 24, "Blue");
}

void RecommendButton::ContentView() {
	myDrawCircle->View();
	text->View();
	textSub->View();
}

RecommendButton::~RecommendButton() {
	delete text;
	delete myDrawCircle;
	delete textSub;
}