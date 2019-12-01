// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project


#include "Position.h"


Position :: Position(): posX(0) , posY(0) {
}

Position :: Position(int x, int y): posX(x) , posY(y) {

}

Position :: Position(const Position& rhs) {
	this->setPosX(rhs.getPosX());
	this->setPosY(rhs.getPosY());
}


int Position::getPosX() const {
	return (posX);
}

void Position::setPosX(int posX) {
	this->posX = posX;
}

int Position::getPosY() const {
	return (posY);
}

void Position::setPosY(int posY) {
	this->posY = posY;
}
