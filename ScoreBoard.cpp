// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "ScoreBoard.h"

ScoreBoard :: ScoreBoard(): GameObject(0,0) , NumberOfLives(2) , Score(0) , highScore(0) , scoreCheck(10000) , level(1) {
}

ScoreBoard :: ScoreBoard(int x,int y,int nol,int score): GameObject(x,y) , NumberOfLives(nol) , Score(score) , highScore(0) , scoreCheck(10000), level(1) {
}

ScoreBoard :: ScoreBoard(const ScoreBoard& rhs): GameObject(rhs.getX(),rhs.getY()) {
	this->NumberOfLives = rhs.getNumberOfLives();
	this->Score = rhs.getScore();
	this->highScore = rhs.getHighScore();
	this->scoreCheck = 10000;
	this->level = 1;
}

void ScoreBoard :: retrieveHighScore() {

////for restoring value of high score back in game////
	ifstream InputFile;
	if(InputFile) {
		InputFile.open("HighScore.txt", ios::in);
		InputFile>>this->highScore;
		InputFile.close();
	}
	else cout<<"File not Opened\n";
///////////////////////////////////////////////////////
}


void ScoreBoard :: saveHighScore() {
	/////////////////////SAVING HIGH SCORE////

	if(this->Score >= this->highScore) {
		this->highScore = this->Score;
	}

	ofstream OutputFile;
	if(OutputFile) {
		OutputFile.open("HighScore.txt", ios::out);
		OutputFile<<this->highScore;
		OutputFile.close();
	}
	else cout<<"File not Opened\n";

	//////////////////////////////////////////
}

void ScoreBoard :: draw() {
	DrawLine(10, 610, 1010,  610, 3, colors[45]); //line below

	DrawString( 40, 615, "Score : ", colors[45]);
	DrawString( 150, 615 , to_string(this->Score), colors[45]);

	DrawString( 300, 615, "HighScore : ", colors[45]);
	DrawString( 450, 615 , to_string(this->highScore), colors[45]);

	DrawString( 900, 615 , "Lives : ", colors[45]);
	DrawString( 970, 615, to_string(this->NumberOfLives), colors[45]);

	DrawString( 600, 615 , "Level : ", colors[45]);
	DrawString( 670, 615, to_string(this->level), colors[45]);


	if(this->Score >= (this->scoreCheck) ) {
		if(this->NumberOfLives<6) {
			this->NumberOfLives++;
			this->scoreCheck += 10000;
		}
	}
	if(this->Score >= 999999) {
		this->Score = 999999;
	}
}

int ScoreBoard::getNumberOfLives() const {
	return NumberOfLives;
}

void ScoreBoard::setNumberOfLives(int numberOfLives) {
	NumberOfLives = numberOfLives;
}

int ScoreBoard::getScore() const {
	return Score;
}

int ScoreBoard::getHighScore() const {
	return highScore;
}

int ScoreBoard::getScoreCheck() const {
	return scoreCheck;
}

int ScoreBoard::getLevel() const {
	return level;
}

void ScoreBoard::setLevel(int level) {
	this->level = level;
}

void ScoreBoard::setScoreCheck(int scoreCheck) {
	this->scoreCheck = scoreCheck;
}

void ScoreBoard::setHighScore(int highScore) {
	this->highScore = highScore;
}

void ScoreBoard::setScore(int score) {
	Score = score;
}

ScoreBoard :: ~ScoreBoard() {
}

