#include "ThroughResultObject.h"

ScoreBar::ScoreBar(Font *font, const float y, const char *title, const char *para1, const char *para2)
 : Draw(WIDTH * 0.475, y) {
	const float height = 110;
	this->title = new MyDrawTextLine(font, title, GetX(), GetY(), 0, 24, WIDTH * 0.3, 2);
	mark = new MyDrawGraph(0, GetY() + height - 50, "img/mark.png");
	score = new MyDrawText(font, "", 0, GetY() + height - 55, ALIGNMENT_CENTER, 30);
	para[0] = new MyDrawText(font, para1, GetX() - 100, GetY() + height, ALIGNMENT_RIGHT, 20);
	para[1] = new MyDrawText(font, para2, GetX() + 100, GetY() + height, ALIGNMENT_LEFT, 20);
	for (int i = 0; i < 8; i++)
		box[i] = new MyDrawBox(GetX() - 77 + i * 22, GetY() + height, 20, 40);
}

void ScoreBar::Load(const int p) {
	char point[10];
	sprintf_s(point, sizeof(point), "%d", p);
	mark->Load();
	const float x = GetX() - 88 + p * 22;
	mark->ChangePos(x, mark->GetY());
	score->ChangePos(x, score->GetY());
	score->ChangeText(point);
	for (int i = 0; i < 8; i++) {
		if (i < p)
			box[i]->SetAlpha();
		else
			box[i]->SetAlpha(100);
	}
}

void ScoreBar::ContentView() {
	title->View();
	mark->View();
	score->View();
	for (int i = 0; i < 2; i++)
		para[i]->View();
	for (int i = 0; i < 8; i++)
		box[i]->View();
}

ScoreBar::~ScoreBar() {
	delete title;
	delete mark;
	delete score;
	for (int i = 0; i < 2; i++)
		delete para[i];
	for (int i = 0; i < 8; i++)
		delete box[i];
}

TimingBar::TimingBar(Font *font) : ScoreBar(font, HEIGHT * 0.44, "タイミング", "slow", "early") {}

ExpressionBar::ExpressionBar(Font *font) : ScoreBar(font, HEIGHT * 0.54, "表情", "bad", "good") {}

ResultComment::ResultComment(Font *font)
	: Draw(WIDTH * 0.6, HEIGHT * 0.64) {
	title = new MyDrawTextLine(font, "コメント", GetX(), GetY(), ALIGNMENT_LEFT, 24, WIDTH * 0.55, 2);
	//comment = new MyDrawTexts(font, "Bメロからサビに入ってからサビの終わりにかけてが苦手のように思います。そこを重点的に練習しましょう。", WIDTH * 0.35, WIDTH * 0.5, GetY() + 70, ALIGNMENT_LEFT, 20, 16);
	comment = new MyDrawTexts(font, "", WIDTH * 0.35, GetY() + 70, ALIGNMENT_LEFT, 20, 16);
}
 
void ResultComment::Load(const char *str) {

	//comment->MakeNewLine(str, WIDTH*0.4);
	comment->MakeNewLine("Bメロからサビに入ってからサビの終わりにかけてが苦手のように思います。そこを重点的に練習しましょう。", WIDTH*0.5);
}

void ResultComment::ContentView() {
	title->View();
	comment->View();
}

ResultComment::~ResultComment() {
	delete title;
	delete comment;
}

ResultBody::ResultBody(Font *font) 
	: Draw(WIDTH * 0.8, HEIGHT * 0.53) {
	body = new MyDrawGraph(GetX(), GetY(), "img/man.png");
	part[0] = new MyDrawText(font, "左手", GetX() - 106, GetY() - 68, ALIGNMENT_CENTER, 20);
	part[1] = new MyDrawText(font, "右手", GetX() + 140, GetY() - 55, ALIGNMENT_CENTER, 20);
	part[2] = new MyDrawText(font, "左足", GetX() - 100, GetY() + 68, ALIGNMENT_CENTER, 20);
	part[3] = new MyDrawText(font, "右足", GetX() + 122, GetY() + 55, ALIGNMENT_CENTER, 20);
	
	point[0] = new MyDrawText(font, "", GetX() - 147, GetY() - 70, ALIGNMENT_CENTER, 30, "");
	point[1] = new MyDrawText(font, "", GetX() + 99, GetY() - 57, ALIGNMENT_CENTER, 30, "");
	point[2] = new MyDrawText(font, "", GetX() - 141, GetY() + 66, ALIGNMENT_CENTER, 30, "");
	point[3] = new MyDrawText(font, "", GetX() + 81, GetY() + 53, ALIGNMENT_CENTER, 30, "");
}

void ResultBody::Load(const int point[4]) {
	body->Load();
	for (int i = 0; i < 4; i++) {
		
		switch (point[i]) {
		case 1:
			this->point[i]->ChangeText("A");
			this->point[i]->ChangeColor("Red");
			break;
		case 2:
			this->point[i]->ChangeText("B");
			this->point[i]->ChangeColor("Yellow");
			break;
		case 3:
			this->point[i]->ChangeText("C");
			this->point[i]->ChangeColor("Green");
			break;
		}
	}
}

void ResultBody::ContentView() {
	body->View();
	for (int i = 0; i < 4; i++) {
		part[i]->View();
		point[i]->View();
	}
}

void ResultBody::Delete() {
	body->Release();
}

ResultBody::~ResultBody() {
	delete body;
	for (int i = 0; i < 4; i++) {
		delete part[i];
		delete point[i];

	}
}

ResultGraph::ResultGraph(Font *font) 
	: Draw(WIDTH * 0.65, HEIGHT * 0.32) {
	this->font = font;

	this->vertexNum = 0;

	text = new MyDrawText(font, "区間別採点", WIDTH*0.35, HEIGHT*0.245, 0, 20);
	frame[0] = new MyDrawLine(GetX() - w / 2, GetY() - h / 2, GetX() - w / 2, GetY() + h / 2, 8, "White");
	frame[1] = new MyDrawLine(GetX() - w / 2, GetY() + h / 2, GetX() + w / 2, GetY() + h / 2, 8, "White");
	scale = new MyDrawTexts(font, "100\n・\n・\n・\n・\n50\n・\n・\n・\n・\n0", GetX() - w / 2 - WIDTH * 0.025, GetY(), 1, 20, 4);
	AddVertex(GetX() + w / 2, GetY() + h / 2);
	AddVertex(GetX() - w / 2, GetY() + h / 2);
}

void ResultGraph::AddVertex(float x, float y) {
	vertex_x[vertexNum] = x;
	vertex_y[vertexNum] = y;
	vertexNum++;
}

void ResultGraph::Load(const int *point, const int num, Song *song) {
	pointMax = num;
	partMax = song->GetPartNum();
	
	for (int i = 0; i < num; i++) {
		float x1 = GetX() - w / 2 + (float)i / (num - 1) * w;
		float y1 = GetY() + h / 2 - (float)point[i] / 100 * h;
		AddVertex(x1, y1);
		if (i > 0) {
			float x2 = GetX() - w / 2 + (float)(i - 1) / (num - 1) * w;
			float y2 = GetY() + h / 2 - (float)point[i - 1] / 100 * h;
			line[i - 1] = new MyDrawLine(x1, y1, x2, y2, 3);
		}
		dot[i] = new MyDrawGraph(x1, y1, "img/star.png", 0.1);
		dot[i]->Load();
		if (point[i] > 80)
			dot[i]->SetViewFlag(TRUE);
		else
			dot[i]->SetViewFlag(FALSE);
	}

	for (int i = 0; i < partMax; i++) {
		SongPart *songPart = song->GetPart(i);
		float x = GetX() - w / 2 + w * (float)songPart->GetFlame() / song->danceMovie->GetEndFlame();
		part[i] = new MyDrawTextV(font, songPart->GetName(),  x, GetY() + HEIGHT * 0.075, 2, 16);
	}
	graph = new MyDrawPolygon(vertex_x, vertex_y, vertexNum, "Blue");
}

void ResultGraph::ContentView() {
	graph->View();
	for (int i = 0; i < partMax; i++)
		part[i]->View();
	for (int i = 0; i < pointMax - 1; i++)
		line[i]->View();
	for(int i = 0; i < pointMax; i++)
		dot[i]->View();
	for (int i = 0; i < 2; i++)
		frame[i]->View();
	scale->View();
	text->View();
}

void ResultGraph::Delete() {
	for (int i = 0; i < pointMax; i++) {
		delete dot[i];
		if (i > 0)
			delete line[i - 1];
	}
	for (int i = 0; i < partMax; i++)
		delete part[i];
	graph->Delete();
}

ResultGraph::~ResultGraph() {
	for (int i = 0; i < 2; i++)
		delete frame[i];
	scale->View();
}