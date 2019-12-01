// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef MUSHROOM_H_
#define MUSHROOM_H_

#include "GameObject.h"

class Mushroom: public GameObject {

private:
	int health;
	bool Collision;

public:
	Mushroom();
	Mushroom(int x,int y);
	Mushroom getMushroom() {
		return *this;
	}
	Mushroom(const Mushroom& rhs);
	virtual void checkCollision(int x1,int y1);
	virtual void draw();
	virtual ~Mushroom();
	Mushroom operator=(const Mushroom& rhs);

	int getHealth() const;
	void setHealth(int health);
	bool isCollision() const;
	void setCollision(bool collision);
	void setMY(int y);
	int getMY()const;
	void setMX(int x);
	int getMX()const;
};

#endif /* MUSHROOM_H_ */
