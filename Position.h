// Abdullah Naveed
// ROLL # 18I-0654 (A)
// OOP_Project

#ifndef POSITION_H_
#define POSITION_H_

class Position {

private:
	int posX;
	int posY;

public:
	Position();
	Position(int x, int y);
	Position(const Position& rhs);

	int getPosX() const;
	void setPosX(int posX);
	int getPosY() const;
	void setPosY(int posY);
};

#endif /* POSITION_H_ */
