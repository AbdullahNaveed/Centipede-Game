// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef SCORPION_H_
#define SCORPION_H_

#include "MoveableObject.h"
#include "Mushroom.h"

class Scorpion: public MoveableObject {

private:
	bool collision;
	int timer;
	int countTimer;
	Mushroom whiteMushroom;

public:
	Scorpion();
	virtual ~Scorpion();
	virtual void draw();
	virtual void move(int x1,int y1);
	virtual void checkCollision(int x1,int y1);

	bool isCollision() const;
	void setCollision(bool collision);
	int getTimer() const;
	void setTimer(int timer);
	int getCountTimer() const;
	void setCountTimer(int countTimer);
	int getMushroomX()const;
	void setMushroomX(int x);
	int getMushroomY()const;
	void setMushroomY(int y);
};

#endif /* SCORPION_H_ */
