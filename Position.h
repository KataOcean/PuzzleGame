#pragma once

class Position {
private:
	int x;
	int y;
public:
	Position():x(0), y(0) {};
	Position(int _x, int _y) : x(_x), y(_y) {};

	int GetX() { return this->x; }
	int GetY() { return this->y; }

	void SetX(int _x) { this->x = _x; }
	void SetY(int _y) { this->y = _y; }
};