// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_

#include "GameObject.h"

class MoveableObject: public GameObject {

public:
	MoveableObject();
	MoveableObject(int x,int y);
	MoveableObject(const MoveableObject& rhs);
	virtual void draw();
	virtual void move(int x,int y) = 0;
	virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */
