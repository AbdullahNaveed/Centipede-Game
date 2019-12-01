// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "MagicSeg.h"

MagicSeg :: MagicSeg(): color(15) , colorTimer(0) , collision(false) {
}

MagicSeg :: MagicSeg(int x,int y): Segment(x,y) , color(15) , colorTimer(0) , collision(false) {
}

void MagicSeg :: draw() {

		DrawCircle(this->getX() , this->getY() , 8 , colors[this->color]);

		DrawSquare(this->getX()-5 , this->getY()+4 , 5 , colors[this->color]); //upper leg
		DrawSquare(this->getX()-5 , this->getY()+6 , 5 , colors[this->color]);
		DrawSquare(this->getX()-7 , this->getY()+8 , 5 , colors[this->color]);

		DrawSquare(this->getX()-5 , this->getY()-8 , 5 , colors[this->color]); //lower leg
		DrawSquare(this->getX()-5 , this->getY()-10 , 5 , colors[this->color]);
		DrawSquare(this->getX()-7 , this->getY()-12 , 5 , colors[this->color]);

		this->colorTimer++;
		if( colorTimer%50 == 0 ){
			this->color++;

			if(this->color == 50) {
				this->color = 15;
			}
		}
}

void MagicSeg :: checkCollision(int x1, int y1) {

	if( ( (this->getX() >= x1-14) &&  (this->getX() <= x1+1) ) && (this->getY() == y1) )
		this->setCollision(true);
}

void MagicSeg :: move(int x,int y) {
	this->setX(x);
	this->setY(640 - y);
}

int MagicSeg::getColor() const {
	return color;
}

int MagicSeg::getColorTimer() const {
	return colorTimer;
}

bool MagicSeg::isCollision() const {
	return collision;
}

void MagicSeg::setCollision(bool collision) {
	this->collision = collision;
}

void MagicSeg::setColorTimer(int colorTimer) {
	this->colorTimer = colorTimer;
}

void MagicSeg::setColor(int color) {
	this->color = color;
}

MagicSeg :: ~MagicSeg() {
}

