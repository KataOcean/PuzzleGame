#pragma once

#include "Position.h"
#include "CellType.h"
#include <vector>

using namespace std;

class StageData {
private:
	int width;
	int height;
	CellType* cells;
	Position playerPosition;
	vector<Position> baggagePositions;

	int GetIndex(int x, int y) { return (y * this->width) + x; }
public:
	StageData(const char* fileName);
	~StageData();

	int GetSize();

	CellType GetFloor(int x, int y) {
		if (GetIndex(x, y) < GetSize()) return this->cells[GetIndex(x, y)];
		else return WALL;
	}
	void SetFloor(int x, int y, CellType value) {
		if (GetIndex(x, y) >= GetSize())return;
		this->cells[GetIndex(x, y)] = value;
	}

	Position GetPlayerPosition() {
		return this->playerPosition;
	}
	vector<Position> GetBaggagePositions() {
		return baggagePositions;
	}

	int GetWidth() {
		return this->width;
	}

	int GetHeight() {
		return this->height;
	}

	static CellType GetCellType(const char cell);
};