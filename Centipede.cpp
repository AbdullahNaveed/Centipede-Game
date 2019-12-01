// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Centipede.h"

Centipede :: Centipede(): head(250,620) , sizeOfBody(10) , checkStatus(true) , hitCenter(false) , movingDown(true) , headCollisionAfterBody(false) {
	this->body = new LazySeg[sizeOfBody];
	this->checkingCollisionXY = new int[this->sizeOfBody];
	for(int i=0 ; i<this->sizeOfBody ; i++) {
		this->checkingCollisionXY[i] = 0;
	}
}

Centipede :: Centipede(int x,int y): head(x,y) , sizeOfBody(10) , checkStatus(true), hitCenter(false) , movingDown(true) , headCollisionAfterBody(false) {
	this->body = new LazySeg[sizeOfBody];
	this->checkingCollisionXY = new int[this->sizeOfBody];
	for(int i=0 ; i<this->sizeOfBody ; i++) {
		this->checkingCollisionXY[i] = 0;
	}
}

bool Centipede :: getHeadCollision() const {
	return (this->head.isCollision());
}
void Centipede :: setHeadCollision(bool set) {
	this->head.setCollision(set);
}

int Centipede :: getHeadX() const {
	return this->head.getX();
}
void Centipede :: setHeadX(int x) {
	this->head.setX(x);
}
int Centipede :: getHeadY() const {
	return this->head.getY();
}

bool Centipede::isHitCenter() const {
	return hitCenter;
}

bool Centipede::isMovingDown() const {
	return movingDown;
}

void Centipede::setMovingDown(bool movingDown) {
	this->movingDown = movingDown;
}

void Centipede::setHitCenter(bool hitCenter) {
	this->hitCenter = hitCenter;
}

void Centipede :: setHeadY(int y) {
	this->head.setY(y);
}

int Centipede::getSizeOfBody() const {
	return sizeOfBody;
}

bool Centipede::isCheckStatus() const {
	return checkStatus;
}

void Centipede::setCheckStatus(bool checkStatus) {
	this->checkStatus = checkStatus;
}

void Centipede::setSizeOfBody(int sizeOfBody) {
	this->sizeOfBody = sizeOfBody;
}

void Centipede::setCheckingCollisionXY(int index) {
	this->checkingCollisionXY[index] = 1;
}
int Centipede::getCheckingCollisionXY(int index) {
	 return this->checkingCollisionXY[index];
}

Centipede :: ~Centipede() {
}

bool Centipede :: getCollisionStatusToDrawMushroom(int index) {
	if( (this->body[index].getCollisionX() != (-30) ) && (this->body[index].getCollisionY() != (-30) )) {
		return true;
	}
	return false;
}

int Centipede :: getCollisionX(int index) const {
	return this->body[index].getCollisionX();
}

int Centipede :: getCollisionY(int index) const {
	return this->body[index].getCollisionY();
}

void Centipede :: draw() {

	if(this->headCollisionAfterBody == false)
	this->head.draw();

	for(int i=0 ; i<this->sizeOfBody ; i++) {
		this->body[i].draw();
	}
}

void Centipede :: checkCollisionOfCentipede(int x,int y) {

	for(int i=0 ; i<this->sizeOfBody ; i++) {

		this->body[i].checkCollision(x,y);
		this->head.checkCollision(x,y);

		if(this->body[i].isCollision() == true) {
			if( i == (this->sizeOfBody/2) ) {
				this->hitCenter = true;
			}
		}

		if(this->body[i].isCollision() == true && (this->checkingCollisionXY[i] == 0) ) {
			this->body[i].setCollisionX(this->body[i].getX());
			this->body[i].setCollisionY(this->body[i].getY());
		}
	}

	int counter = 1;
	for(int i=0 ; i<this->sizeOfBody ; i++) {

		if(this->checkingCollisionXY[i] == 1) {
			counter++;
		}
	}

	if(counter >= this->sizeOfBody) {
		this->headCollisionAfterBody = true;
	}

}

void Centipede :: moveCentipede(int x,int y) {

	if(this->getHeadY() <= 20 ) {
		this->movingDown = false;
	}
	if(this->getHeadY() >= 630 ) {
		this->movingDown = true;
	}

	if(this->movingDown == true) {
		if(this->head.getX() >= 1010) {				//when head reaches boundary to right
			this->head.setY(this->head.getY()-15);
			this->checkStatus = false;
		}
		if(this->head.getX() <= 10) {				//when head reaches boundary to left
			this->head.setY(this->head.getY()-15);
			this->checkStatus = true;
		}

		if(this->head.getX() != 1010 && this->checkStatus == true) {
			this->head.setX(this->head.getX()+5);
		}
		if(this->head.getX() != 10 && this->checkStatus == false) {
			this->head.setX(this->head.getX()-5);
		}
	}

	if(this->movingDown == false) {
		if(this->head.getX() >= 1010) {				//when head reaches boundary to right
			this->head.setY(this->head.getY()+15);
			this->checkStatus = false;
		}
		if(this->head.getX() <= 10) {				//when head reaches boundary to left
			this->head.setY(this->head.getY()+15);
			this->checkStatus = true;
		}

		if(this->head.getX() != 1010 && this->checkStatus == true) {
			this->head.setX(this->head.getX()+5);
		}
		if(this->head.getX() != 10 && this->checkStatus == false) {
			this->head.setX(this->head.getX()-5);
		}
	}

		int counter = 1;

		if(this->checkStatus == true) {

			for(int i=0 ; i<this->sizeOfBody ; i++) {

				if( (this->body[i].isCollision()) == false) {
					this->body[i].move(this->head.getX()-(15*counter), 640 - this->head.getY() );
					counter++;
				}
			}
		}


		if(this->checkStatus == false) {

			for(int i=0 ; i<this->sizeOfBody ; i++) {
				if( (this->body[i].isCollision()) == false) {
					this->body[i].move(this->head.getX()+(15*counter), 640 - this->head.getY() );
					counter++;
				}
			}
		}
}

bool Centipede::isHeadCollisionAfterBody() const {
	return headCollisionAfterBody;
}

void Centipede::setHeadCollisionAfterBody(bool headCollisionAfterBody) {
	this->headCollisionAfterBody = headCollisionAfterBody;
}
