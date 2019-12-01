// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "GunFire.h"

GunFire :: GunFire(): GameObject(0,0) , direction('n') {
}

GunFire :: GunFire(int x, int y): GameObject(x,y) , direction('n') {
}

void GunFire :: draw() {
	DrawSquare(this->getX()-10,this->getY()-3,5,colors[ORANGE]);
}

char GunFire::getDirection() const {
	return direction;
}

void GunFire::setDirection(char direction) {
	this->direction = direction;
}

GunFire :: ~GunFire() {
}

