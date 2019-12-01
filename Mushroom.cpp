// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "Mushroom.h"

Mushroom :: Mushroom(): GameObject(rand()%970+30,rand()%440+ 140) , health(100), Collision(false)  {
}

Mushroom :: Mushroom(int x,int y): GameObject(x,y) , health(100), Collision(false) {
}

Mushroom :: Mushroom(const Mushroom& rhs): GameObject(rhs.getX(),rhs.getY()), Collision(false) {
	this->health = rhs.getHealth();
}

void Mushroom :: checkCollision(int x1,int y1) {

	if( ( (this->getX() >= x1-14) &&  (this->getX() <= x1+1) ) && (this->getY() == y1) )
	this->health -=35;

	cout<<"health"<<this->health<<endl;

	if(this->health <= 0) {
		this->Collision = true;
		this->setX(-100);
		this->setY(-100);
	}
}

void Mushroom :: setMY(int y) {
	this->setY(640 - y);
}
int Mushroom :: getMY() const {
	return ( this->getY() );
}
void Mushroom :: setMX(int x) {
	this->setX(x);
}

int Mushroom :: getMX() const {
	return ( this->getX() );
}

int Mushroom::getHealth() const {
	return health;
}

bool Mushroom::isCollision() const {
	return Collision;
}

void Mushroom::setCollision(bool collision) {
	Collision = collision;
}

void Mushroom::setHealth(int health) {
	this->health = health;
}

Mushroom :: ~Mushroom() {
}

Mushroom Mushroom :: operator=(const Mushroom& rhs) {
	this->setX(rhs.getX());
	this->setY(rhs.getY());

	return *this;
}

void Mushroom :: draw() {

	if(this->Collision == false) {
		DrawSquare(this->getX()-4,this->getY()-8,8,colors[YELLOW]);
		DrawCircle(this->getX(),this->getY()+1,5,colors[RED]);
	}
}

