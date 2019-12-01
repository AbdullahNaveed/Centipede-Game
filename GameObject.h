// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include<iostream>
#include<string>
#include <cstdlib>
#include<time.h>
#include "Position.h"
#include "util.h"

using namespace std;

class GameObject {

private:
	Position position;

public:
	GameObject();
	GameObject(int x,int y);
	virtual void draw() = 0; //to make it abstract class
	virtual ~GameObject();

	int getX() const;
	void setX(int posX);
	int getY() const;
	void setY(int posY);

};

#endif /* GAMEOBJECT_H_ */
