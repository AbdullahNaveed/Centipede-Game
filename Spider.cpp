// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Spider.h"

Spider :: Spider(): MoveableObject(30,30) ,  checkStatusX(true) , checkStatusY(true) , collision(false) {
}

bool Spider::isCheckStatusX() const {
	return checkStatusX;
}

void Spider::setCheckStatusX(bool checkStatusx) {
	this->checkStatusX = checkStatusx;
}

Spider::~Spider() {
	this->collision = true;
}

void Spider :: move(int x1,int y1) {

	if(this->getX() != 1010 && this->checkStatusX == true) {	 //when reaches boundary to right
		this->setX(this->getX()+1);
	}
	if(this->getX() != 10 && this->checkStatusX == false) {	//when reaches boundary to left
		this->setX(this->getX()-1);
	}

	if(this->getX() >= 1010) {
		this->checkStatusX = false;
	}
	if(this->getX() <= 10) {
		this->checkStatusX = true;
	}

	if(this->getY() != 250 && this->checkStatusY == true) {	 //when reaches boundary to right
		this->setY(this->getY()+3);
	}
	if(this->getY() != 10 && this->checkStatusY == false) {	//when reaches boundary to left
		this->setY(this->getY()-3);
	}

	if(this->getY() >= 250) {
		this->checkStatusY = false;
	}
	if(this->getY() <= 10) {
		this->checkStatusY = true;
	}

}
void Spider :: draw() {

	if(this->collision == false) {
		DrawCircle(this->getX() , this->getY() , 8 , colors[WHITE]);

		DrawSquare(this->getX()-9 , this->getY() , 5 , colors[WHITE]); //left  center leg
		DrawSquare(this->getX()-11 , this->getY() , 5 , colors[WHITE]);
		DrawSquare(this->getX()-13 , this->getY() , 5 , colors[WHITE]);
		DrawSquare(this->getX()-14 , this->getY()-1 , 5 , colors[WHITE]);

		DrawSquare(this->getX()-9 , this->getY()-6 , 5 , colors[WHITE]); //left  lower leg
		DrawSquare(this->getX()-11 , this->getY()-6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()-13 , this->getY()-6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()-14 , this->getY()-8 , 5 , colors[WHITE]);

		DrawSquare(this->getX()-9 , this->getY()+6 , 5 , colors[WHITE]); //left  upper leg
		DrawSquare(this->getX()-11 , this->getY()+6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()-13 , this->getY()+6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()-8 , this->getY()+5 , 5 , colors[WHITE]);
		DrawSquare(this->getX()-8 , this->getY()+4 , 5 , colors[WHITE]);

		DrawSquare(this->getX()+5 , this->getY() , 5 , colors[WHITE]); //right center leg
		DrawSquare(this->getX()+7 , this->getY() , 5 , colors[WHITE]);
		DrawSquare(this->getX()+9 , this->getY() , 5 , colors[WHITE]);
		DrawSquare(this->getX()+10 , this->getY()-1 , 5 , colors[WHITE]);

		DrawSquare(this->getX()+5 , this->getY()+6 , 5 , colors[WHITE]); //right  upper leg
		DrawSquare(this->getX()+7 , this->getY()+6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()+9 , this->getY()+6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()+4 , this->getY()+5 , 5 , colors[WHITE]);
		DrawSquare(this->getX()+4 , this->getY()+4 , 5 , colors[WHITE]);

		DrawSquare(this->getX()+5 , this->getY()-6 , 5 , colors[WHITE]); //right lower leg
		DrawSquare(this->getX()+7 , this->getY()-6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()+9 , this->getY()-6 , 5 , colors[WHITE]);
		DrawSquare(this->getX()+10 , this->getY()-8 , 5 , colors[WHITE]);
	}
}

bool Spider::isCheckStatusY() const {
	return checkStatusY;
}

bool Spider::isCollision() const {
	return collision;
}

void Spider::setCollision(bool collision) {
	this->collision = collision;
}

void Spider::setCheckStatusY(bool checkStatusY) {
	this->checkStatusY = checkStatusY;
}

void Spider :: checkCollision(int x1,int y1) {

	if( ( (this->getX() >= x1-18) &&  (this->getX() <= x1+3) ) && ( (this->getY() >= y1-10) &&  (this->getY() <= y1+1) ) )
		this->collision = true;
}
