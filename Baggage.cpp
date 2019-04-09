#include "Baggage.h"

Baggage::Baggage(int _x, int _y) {
	this->position = new Position(_x, _y);
}

Baggage::~Baggage() {
	delete this->position;
}

void Baggage::Move(int _x, int _y) {
	this->position->SetX(_x);
	this->position->SetY(_y);
}