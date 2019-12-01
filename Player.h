// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef PLAYER_H_
#define PLAYER_H_

#include "MoveableObject.h"
#include "GunFire.h"
#include "Objects.h"

class Player: public MoveableObject {

private:
	GunFire *bullet;
	bool fired;
	bool mouse;
	bool Collision;
	char movement;

public:
	Player();
	Player(int x,int y);
	Player getPlayer() {
		return *this;
	}
	virtual void draw();
	void drawBullet();
	virtual void move(int x, int y);
	void checkCollision(int x1,int y1);
	virtual ~Player();

	void setBulletY(int y);
	int getBulletY() const;
	void setBulletX(int x);
	int getBulletX() const;
	bool isFired() const;
	void setFired(bool fired);
	bool isMouse() const;
	void setMouse(bool mouse);
	bool isCollision() const;
	void setCollision(bool collision);
	char getMovement() const;
	void setMovement(char movement);
};

#endif /* PLAYER_H_ */
