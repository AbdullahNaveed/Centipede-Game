// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Player.h"

Player :: Player(): MoveableObject(500,10) , fired(false) , mouse(0) , Collision(false) , movement('n') {
	bullet = new GunFire;
}

Player :: Player(int x, int y): MoveableObject(x,y) , fired(false) , mouse(0) , Collision(false) , movement('n') {
	bullet = new GunFire;
}

void Player :: draw() {

	if(this->Collision == false) {

		DrawSquare(this->getX()-10,this->getY()-5,5,colors[RED]); //Left hand
		DrawSquare(this->getX()-8,this->getY()-5,5,colors[RED]); //Left hand
		DrawSquare(this->getX()-9,this->getY()-5,5,colors[RED]); //Left hand
		DrawSquare(this->getX()-12,this->getY()-3,5,colors[WHITE]); //Left hand gun
		//this->bullet->draw();
		DrawSquare(this->getX()+8,this->getY()-5,5,colors[RED]); //Right hand
		DrawSquare(this->getX()+7,this->getY()-5,5,colors[RED]); //Right hand
		DrawSquare(this->getX()+6,this->getY()-5,5,colors[RED]); //Right hand

		DrawCircle(this->getX()-3,this->getY()-12,3,colors[RED]); //left leg
		DrawCircle(this->getX()+5,this->getY()-12,3,colors[RED]); //right leg

		DrawSquare(this->getX()-4,this->getY()-12,10,colors[BLUE]); //body
		DrawCircle(this->getX(),this->getY()+1,7,colors[BROWN]); //head
	}

}

void Player :: setBulletY(int y) {
	this->bullet->setY(y);
}

int Player :: getBulletY() const {
	return this->bullet->getY();
}

void Player :: setBulletX(int x) {
	this->bullet->setX(x);
}

bool Player::isFired() const {
	return fired;
}

bool Player::isMouse() const {
	return mouse;
}

bool Player::isCollision() const {
	return Collision;
}

char Player::getMovement() const {
	return movement;
}

void Player::setMovement(char movement) {
	this->movement = movement;
}

void Player::setCollision(bool collision) {
	Collision = collision;
}

void Player::setMouse(bool mouse) {
	this->mouse = mouse;
}

void Player::setFired(bool fired) {
	this->fired = fired;
}

int Player :: getBulletX() const {
	return this->bullet->getX();
}

void Player :: drawBullet() {
	this->bullet->draw();
}

void Player :: move(int x,int y) {

	this->setX(x);
	this->setY(640 -y);

	if(this->getY()>200) {
		this->setY(200);
	}

	if(fired == false) {
		this->setBulletY(this->getY()-1);
		this->setBulletX(this->getX()-2);
	}
}

void Player :: checkCollision(int x1,int y1) {

	if( ( (this->getX() >= x1-15) &&  (this->getX() <= x1+10) ) && ( (this->getY() <= y1+20) && (this->getY() >= y1-20) ) )
		this->Collision = true;
}

Player :: ~Player() {
	this->setX(-100);
	this->setY(-100);

	delete[]this->bullet;
}

