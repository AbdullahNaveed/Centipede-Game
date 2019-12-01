// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Scorpion.h"

Scorpion :: Scorpion(): MoveableObject(-10,rand()%400 + 300) , collision(false) , timer(1) , countTimer(1000) {
}

bool Scorpion::isCollision() const {
	return collision;
}

int Scorpion::getTimer() const {
	return timer;
}

int Scorpion::getCountTimer() const {
	return countTimer;
}

void Scorpion::setCountTimer(int countTimer) {
	this->countTimer = countTimer;
}

void Scorpion::setTimer(int timer) {
	this->timer = timer;
}

void Scorpion::setCollision(bool collision) {
	this->collision = collision;
}

Scorpion::~Scorpion() {
}

void Scorpion :: draw() {

	DrawSquare(this->getX() , this->getY() , 10 , colors[WHITE]);
	DrawSquare(this->getX()-10 , this->getY() , 10 , colors[WHITE]);
	DrawSquare(this->getX()-11 , this->getY()+8 , 5 , colors[WHITE]);
	DrawSquare(this->getX()-11 , this->getY()+10 , 4 , colors[WHITE]);
	DrawSquare(this->getX()-8 , this->getY()+10 , 4 , colors[WHITE]);
	DrawSquare(this->getX()-5 , this->getY()+10 , 3 , colors[WHITE]);
	DrawSquare(this->getX()-3 , this->getY()+10 , 2 , colors[WHITE]);
	DrawCircle(this->getX()+6 , this->getY()+5 , 4 , colors[WHITE]);


	if(this->collision == true) {
		this->whiteMushroom.draw();
	}

}

void Scorpion :: move(int x1,int y1) {

	if( timer >= (countTimer) ) {
		this->setX(this->getX()+10);
	}

	if(this->getX() >= 1010) {
		this->setX(-10);
		this->setY(rand()%400 + 300);
		this->timer = 1;
	}

	if(this->collision == false) {
		this->timer += 5;
		this->whiteMushroom.setX(this->getX());
		this->whiteMushroom.setY(this->getY());
	}
}

void Scorpion :: checkCollision(int x1,int y1) {
	if( ( (this->getX() >= x1-18) &&  (this->getX() <= x1+10) ) && ( (this->getY() <= y1+30) && (this->getY() >= y1-35) ) )
		this->collision = true;

	if(this->collision == true) {
		this->whiteMushroom.setY(this->whiteMushroom.getY()-1);

		if(this->whiteMushroom.getY() <= 10) {
			this->collision = false;
		}
	}
}

int Scorpion :: getMushroomX() const {
	return (this->whiteMushroom.getX());
}
void Scorpion :: setMushroomX(int x) {
	this->whiteMushroom.setX(x);
}
int Scorpion :: getMushroomY() const {
	return (this->whiteMushroom.getY());
}
void Scorpion :: setMushroomY(int y) {
	this->whiteMushroom.setY(y);
}
