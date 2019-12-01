// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Objects.h"

Objects :: Objects(): sizeOfMushrooms(20) , gameLoading(true) , pauseGame(false), playGame(false) , loadingCounter(100) , gameOver(false) , level(1) , levelUP(false) , player(550,100) {
	this->mushroom = new Mushroom[this->sizeOfMushrooms];
	this->centipede = new Centipede[2];

	destroyhead[0] = 0;
	destroyhead[1] = 0;

	for(int i=0 ; i<(this->sizeOfMushrooms-1) ; i++) {
		for(int j=i+1 ; j<this->sizeOfMushrooms ; j++) {
				this->mushroom[j].setMY(this->mushroom[j].getMY()-30);
		}
	}

	this->arrayOfObjects[0] = &(this->player);
	this->arrayOfObjects[1] = &(this->spider);
	this->arrayOfObjects[2] = &(info);
	this->arrayOfObjects[3] = &(this->scorpion);

	this->info.retrieveHighScore();
}

void Objects :: refreshMushrooms(int amount) {
	delete[]this->mushroom;
	this->sizeOfMushrooms = amount;
	this->mushroom = new Mushroom[this->sizeOfMushrooms];
}

void Objects :: newSpider() {
	this->spider.setX(30);
	this->spider.setY(30);
	this->spider.setCollision(false);
}

int Objects::getSizeOfMushrooms() const {
	return sizeOfMushrooms;
}

void Objects::setSizeOfMushrooms(int sizeOfMushrooms) {
	this->sizeOfMushrooms = sizeOfMushrooms;
}

void Objects :: nextLevel() {

	if(levelUP == true) {

		this->level++;

		this->info.setLevel(this->level);

		this->refreshMushrooms(level*10);
		this->newSpider();

		delete[]this->centipede;
		this->centipede = new Centipede[2];

		player.setCollision(false);

		this->centipede[0].setHeadCollisionAfterBody(false);
		this->centipede[1].setHeadCollisionAfterBody(false);

		this->setDestroyHead(0,0);
		this->setDestroyHead(1,0);

		this->levelUP = false;
	}
}

bool Objects :: isLevelUp() const {
	return this->levelUP;
}
void Objects :: setLevelUp(bool levelU) {
	this->levelUP = levelU;
}

Objects :: ~Objects() {
}

void Objects :: addMushroom(int x1,int y1) {

	bool check = true;

	for( int i=0 ; i<this->sizeOfMushrooms ; i++ ) { //if there is already mushroom present at that place
		if ( (this->mushroom[i].getX() == x1) && (this->mushroom[i].getY() == y1) ) {
			check = false;
		}
	}

	if(check == true) {

		Mushroom *newMushroom;

		newMushroom = new Mushroom[sizeOfMushrooms+1];

		int i;

		for( i=0 ; i<this->sizeOfMushrooms ; i++ ) {
			newMushroom[i] = this->mushroom[i];
		}
			newMushroom[i].setX(x1);
			newMushroom[i].setY(y1);

		this->sizeOfMushrooms++;

		delete[]this->mushroom;
		this->mushroom = new Mushroom[this->sizeOfMushrooms];

		for( i=0 ; i<this->sizeOfMushrooms ; i++ ) {
			 this->mushroom[i] = newMushroom[i];
		}
	}

/*	for(int i=0 ; i<(this->sizeOfMushrooms-1) ; i++) { //keeping each mushroom 30pixels down
		for(int j=i+1 ; j<this->sizeOfMushrooms ; j++) {
			if( (this->mushroom[i].getMY() >= this->mushroom[j].getMX()-10)   &&  (this->mushroom[i].getMY() <= this->mushroom[j].getMY()+10) ) {
				this->mushroom[j].setMY(this->mushroom[j].getMY()-20);
			}
		}
	} */

	if(this->centipede[0].isHitCenter() == true) {
			if(centipede[0].isCheckStatus() == true) {
				centipede[1].setCheckStatus(false);
			}
			else if(centipede[0].isCheckStatus() == false) {
					centipede[1].setCheckStatus(true);
			}

			this->centipede[0].setHitCenter(false);
	}

	if	(destroyhead[0] == 1 && destroyhead[1] == 1) {
		this->setPlayGame(false);
		this->player.setCollision(false);
		this->setGameLoading(true);

		this->setLevelUp(true);
		this->nextLevel();
	}

}

bool Objects::isGameLoading() const {
	return gameLoading;
}

void Objects::setGameLoading(bool gameLoading) {
	this->gameLoading = gameLoading;
}

bool Objects::isPauseGame() const {
	return pauseGame;
}

bool Objects::isPlayGame() const {
	return playGame;
}

int Objects::getLoadingCounter() const {
	return loadingCounter;
}

void Objects::setLoadingCounter(int loadingCounter) {
	this->loadingCounter = loadingCounter;
}

void Objects::setPlayGame(bool playGame) {
	this->playGame = playGame;
}

void Objects::setPauseGame(bool pauseGame) {
	this->pauseGame = pauseGame;
}

bool Objects::isGameOver() const {
	return gameOver;
}

void Objects::setDestroyHead(int index, int val) {
	this->destroyhead[index] = val;
}
int Objects::getDestroyHead(int index) const {
	return this->destroyhead[index];
}

int Objects::getLevel() const {
	return level;
}

void Objects::setLevel(int level) {
	this->level = level;
}

void Objects::setGameOver(bool gameOver) {
	this->gameOver = gameOver;
}
