// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#include "MoveableObject.h"

MoveableObject :: MoveableObject(): GameObject(0,0) {
	srand(time(NULL));
}

MoveableObject :: MoveableObject(int x,int y): GameObject(x,y) {
}

MoveableObject :: MoveableObject(const MoveableObject& rhs): GameObject(rhs.getX(),rhs.getY()) {
}

MoveableObject :: ~MoveableObject() {
}

void MoveableObject :: draw() {
}
