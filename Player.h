#pragma once

#include "Position.h"

class Player {
private:
	Position *position;
public:
	Player(int _x ,int _y);
	~Player();

	void Move( int _x , int _y );

	int GetX() { return this->position->GetX(); }
	int GetY() { return this->position->GetY(); }
};