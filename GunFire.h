// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef GUNFIRE_H_
#define GUNFIRE_H_

#include "GameObject.h"

class GunFire: public GameObject {

private:
	char direction;

public:
	GunFire();
	GunFire(int x,int y);
	virtual void draw();
	virtual ~GunFire();

	char getDirection() const;
	void setDirection(char direction);
};

#endif /* GUNFIRE_H_ */
