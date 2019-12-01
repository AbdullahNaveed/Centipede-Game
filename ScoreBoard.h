// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "GameObject.h"
#include<fstream>

class ScoreBoard: public GameObject {

private:
	int NumberOfLives;
	int Score;
	int highScore;
	int scoreCheck;
	int level;

public:
	ScoreBoard();
	ScoreBoard(int x,int y,int nol,int score);
	ScoreBoard(const ScoreBoard& rhs);
	virtual void draw();
	void saveHighScore();
	void retrieveHighScore();
	virtual ~ScoreBoard();

	int getNumberOfLives() const;
	void setNumberOfLives(int numberOfLives);
	int getScore() const;
	void setScore(int score);
	int getHighScore() const;
	void setHighScore(int highScore);
	int getScoreCheck() const;
	void setScoreCheck(int scoreCheck);
	int getLevel() const;
	void setLevel(int level);
};

#endif /* SCOREBOARD_H_ */
