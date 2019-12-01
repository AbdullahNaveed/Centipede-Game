// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Segment.h"

Segment :: Segment(): MoveableObject(20,620) , Collision(false) {
}

Segment :: ~Segment() {
}

Segment :: Segment(int x,int y): MoveableObject(x,y) , Collision(false) {
}

void Segment :: draw() {

		DrawCircle(this->getX() , this->getY() , 8 , colors[GREEN]);

		DrawSquare(this->getX()-5 , this->getY()+4 , 5 , colors[GREEN]); //upper leg
		DrawSquare(this->getX()-5 , this->getY()+6 , 5 , colors[GREEN]);
		DrawSquare(this->getX()-7 , this->getY()+8 , 5 , colors[GREEN]);

		DrawSquare(this->getX()-5 , this->getY()-8 , 5 , colors[GREEN]); //lower leg
		DrawSquare(this->getX()-5 , this->getY()-10 , 5 , colors[GREEN]);
		DrawSquare(this->getX()-7 , this->getY()-12 , 5 , colors[GREEN]);

}

void Segment :: move(int x,int y) {

	this->setX(x);
	this->setY(640 - y);
}

void Segment :: checkCollision(int x1, int y1) {
}

bool Segment::isCollision() const {
	return Collision;
}

void Segment::setCollision(bool collision) {
	Collision = collision;
}
