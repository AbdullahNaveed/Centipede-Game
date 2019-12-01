// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef SPIDER_H_
#define SPIDER_H_

#include "MoveableObject.h"

class Spider: public MoveableObject {

private:
	bool checkStatusX;
	bool checkStatusY;
	bool collision;

public:
	Spider();
	virtual ~Spider();

	virtual void move(int x1,int y1);
	virtual void draw();
	virtual void checkCollision(int x1,int y1);
	bool isCheckStatusX() const;
	void setCheckStatusX(bool checkStatus);
	bool isCheckStatusY() const;
	void setCheckStatusY(bool checkStatusY);
	bool isCollision() const;
	void setCollision(bool collision);
};

#endif /* SPIDER_H_ */
