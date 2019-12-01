// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef MAGICSEG_H_
#define MAGICSEG_H_

#include "Segment.h"

class MagicSeg: public Segment {

private:
	int color;
	int colorTimer;
	bool collision;

public:
	MagicSeg();
	MagicSeg(int x,int y);
	virtual ~MagicSeg();
	virtual void draw();
	virtual void move(int x,int y);
	void checkCollision(int x1, int y1);

	int getColor() const;
	void setColor(int color);
	int getColorTimer() const;
	void setColorTimer(int colorTimer);
	bool isCollision() const;
	void setCollision(bool collision);
};

#endif /* MAGICSEG_H_ */
