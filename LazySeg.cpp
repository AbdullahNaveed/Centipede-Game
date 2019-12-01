// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "LazySeg.h"

LazySeg :: LazySeg():  collisionX(-30) , collisionY(-30)  {
}

LazySeg :: LazySeg(int x,int y): Segment(x,y) , collisionX(-30) , collisionY(-30) {
}

void LazySeg :: checkCollision(int x1, int y1) {

	if( ( (this->getX() >= x1-14) &&  (this->getX() <= x1+1) ) && (this->getY() == y1) )
		this->setCollision(true);
}

void LazySeg :: draw() {

	if(this->isCollision() == false) {
		DrawCircle(this->getX() , this->getY() , 8 , colors[GREEN]);

		DrawSquare(this->getX()-5 , this->getY()+4 , 5 , colors[GREEN]); //upper leg
		DrawSquare(this->getX()-5 , this->getY()+6 , 5 , colors[GREEN]);
		DrawSquare(this->getX()-7 , this->getY()+8 , 5 , colors[GREEN]);

		DrawSquare(this->getX()-5 , this->getY()-8 , 5 , colors[GREEN]); //lower leg
		DrawSquare(this->getX()-5 , this->getY()-10 , 5 , colors[GREEN]);
		DrawSquare(this->getX()-7 , this->getY()-12 , 5 , colors[GREEN]);
	}
}

LazySeg :: ~LazySeg() {
}

void LazySeg :: move(int x,int y) {
	this->setX(x);
	this->setY(640 - y);
}

int LazySeg::getCollisionX() const {
	return collisionX;
}

void LazySeg::setCollisionX(int collisionX) {
	this->collisionX = collisionX;
}

int LazySeg::getCollisionY() const {
	return collisionY;
}

void LazySeg::setCollisionY(int collisionY) {
	this->collisionY = collisionY;
}
