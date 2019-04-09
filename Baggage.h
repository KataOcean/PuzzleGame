#pragma once

#include "Position.h"

class Baggage {
private:
	Position *position;
public:
	Baggage(int _x , int _y);
	~Baggage();

	void Move(int _x, int _y);

	int GetX() { return this->position->GetX(); }
	int GetY() { return this->position->GetY(); }
};