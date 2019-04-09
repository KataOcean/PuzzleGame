#pragma once

enum FloorType {
	WALL,
	CEILING,
	GOAL
};

class Stage {
private:
	int width;
	int height;
	FloorType *floors;

	int GetIndex(int x, int y) { return (y * this->width) + x; }
public:
	Stage(int _width, int _height);
	~Stage();


	int GetSize() { return this->width * this->height; }

	FloorType GetFloor(int x, int y) {
		if (GetIndex(x, y) < GetSize()) return this->floors[GetIndex(x, y)];
		else return WALL;
	}
	void SetFloor(int x, int y, FloorType value) {
		if (GetIndex(x, y) >= GetSize())return;
		this->floors[GetIndex(x, y)] = value;
	}

	int GetWidth() { return this->width; }
	int GetHeight() { return this->height; }
};