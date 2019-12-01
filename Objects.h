// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef OBJECTS_H_
#define OBJECTS_H_

#include "Mushroom.h"
#include "Centipede.h"
#include "Spider.h"
#include "GameObject.h"
#include "ScoreBoard.h"
#include "Player.h"
#include "Scorpion.h"

class Objects {

private:
	int  sizeOfMushrooms;
	bool gameLoading;
	bool pauseGame;
	bool playGame;
	int  loadingCounter;
	bool gameOver;
	int  level;
	bool levelUP;
	int destroyhead[2];

public:
	Player player;
	Scorpion scorpion;
	GameObject* arrayOfObjects[4];
	Mushroom *mushroom;
	Centipede *centipede;
	Spider spider;
	ScoreBoard info; //Mushrooms: 1 (destroyed) Centipede: 10 (body) or 100 points (head). Fleas: 200 points.

	Objects();
	void addMushroom(int x1,int y1);
	void refreshMushrooms(int amount);
	virtual ~Objects();
	int getSizeOfMushrooms() const;
	void setSizeOfMushrooms(int sizeOfMushrooms);
	void newSpider();
	bool isGameLoading() const;
	void setGameLoading(bool gameLoading);
	bool isPauseGame() const;
	void setPauseGame(bool pauseGame);
	bool isPlayGame() const;
	void setPlayGame(bool playGame);
	int getLoadingCounter() const;
	void setLoadingCounter(int loadingCounter);
	bool isGameOver() const;
	void setGameOver(bool gameOver);
	int getLevel() const;
	void setLevel(int level);
	void nextLevel();
	bool isLevelUp() const;
	void setLevelUp(bool levelUp);
	void setDestroyHead(int index , int val);
	int getDestroyHead(int index) const ;
};

#endif /* OBJECTS_H_ */
