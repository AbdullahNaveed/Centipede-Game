// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "MoveableObject.h"

class Segment: public MoveableObject {

private:
	bool Collision;

public:
	Segment();
	Segment(int x,int y);
	virtual void draw();
	virtual void move(int x,int y);
	void checkCollision(int x1, int y1);
	virtual ~Segment();
	bool isCollision() const;
	void setCollision(bool collision);
};

#endif /* SEGMENT_H_ */
