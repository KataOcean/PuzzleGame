#include "Baggage.h"

Baggage::Baggage(int _x, int _y) {
	this->position.SetX(_x);
	this->position.SetY(_y);
}

Baggage::Baggage(const Position position)
{
	this->position = position;
}

Baggage::~Baggage() {
}

void Baggage::Move(int _x, int _y) {
	this->position.SetX(_x);
	this->position.SetY(_y);
}