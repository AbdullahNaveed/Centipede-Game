// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "GameObject.h"

GameObject :: GameObject(): position(0,0) {
	srand(time(NULL));
}

GameObject :: GameObject(int x,int y): position(x,y) {
}

GameObject :: ~GameObject() {
}

int GameObject :: getX() const {
	return this->position.getPosX();
}
void GameObject :: setX(int posX) {
	this->position.setPosX(posX);
}
int GameObject :: getY() const {
	return this->position.getPosY();
}
void GameObject :: setY(int posY) {
	return this->position.setPosY(posY);
}
