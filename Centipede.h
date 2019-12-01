// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_

#include "MagicSeg.h"
#include "LazySeg.h"

class Centipede {

private:
	MagicSeg head;
	LazySeg* body;
	int sizeOfBody;
	bool checkStatus; //to check which side centipede is moving
	int *checkingCollisionXY; //array of size of body , when bullet hits, value becomes 1,otherwise 0
	bool hitCenter;
	bool movingDown;
	bool headCollisionAfterBody;

public:
	Centipede();
	Centipede(int x,int y);
	virtual void draw();
	void moveCentipede(int x,int y);
	void checkCollisionOfCentipede(int x,int y);
	bool getCollisionStatusToDrawMushroom(int index);
	virtual ~Centipede();


	int getSizeOfBody() const;
	void setSizeOfBody(int sizeOfBody);
	bool isCheckStatus() const;
	void setCheckStatus(bool checkStatus);
	int getCollisionX(int index) const;
	int getCollisionY(int index) const;
	void setCheckingCollisionXY(int index);
	int getCheckingCollisionXY(int index);
	int getHeadX() const;
	void setHeadX(int x);
	int getHeadY() const;
	void setHeadY(int y);
	bool isHitCenter() const;
	void setHitCenter(bool hitCenter);
	bool isMovingDown() const;
	void setMovingDown(bool movingDown);
	bool isHeadCollisionAfterBody() const;
	void setHeadCollisionAfterBody(bool headCollisionAfterBody);
	bool getHeadCollision()const;
	void setHeadCollision(bool set);
};

#endif /* CENTIPEDE_H_ */
