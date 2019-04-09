#include "Stage.h"

Stage::Stage(int _width, int _height) {
	this->width = _width;
	this->height = _height;

	this->floors = new FloorType[GetSize()];
	for (int y = 0; y < this->height; ++y) {
		for (int x = 0; x < this->width; ++x) {
			if (y == 0 || y == this->height - 1 || x == 0 || x == this->width - 1)this->SetFloor(x, y, WALL);
			else this->SetFloor(x, y, CEILING);
		}
	}

	this->SetFloor(1, 1, GOAL);
	this->SetFloor(4, 1, GOAL);
}

Stage::~Stage() {
	delete[] this->floors;
}