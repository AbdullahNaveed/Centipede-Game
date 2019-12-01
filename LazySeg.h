// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef LAZYSEG_H_
#define LAZYSEG_H_

#include "Segment.h"

class LazySeg: public Segment {

private:
	int collisionX,collisionY;

public:
	LazySeg();
	LazySeg(int x,int y);
	virtual void draw();
	virtual void move(int x,int y);
	virtual void checkCollision(int x1, int y1);
	virtual ~LazySeg();
	int getCollisionX() const;
	void setCollisionX(int collisionX);
	int getCollisionY() const;
	void setCollisionY(int collisionY);
};

#endif /* LAZYSEG_H_ */
