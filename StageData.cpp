#include "StageData.h"
#include "FileReader.h"

StageData::StageData(const char* fileName) {
	this->width = this->height = 0;
	FileReader fr("data/stagedata.dat");

	string data = fr.GetData();

	// width / height ÇÃì«Ç›çûÇ›
	int maxWidth = 1;
	int height = 1;
	int width = 0;
	for (char& cell : data) {
		if (cell == '\n') {
			++height;
			if (maxWidth < width)maxWidth = width;
			width = 0;
			continue;
		}
		++width;
	}

	this->width = maxWidth;
	this->height = height;

	// é¿ç€ÇÃÉfÅ[É^ì«Ç›çûÇ›
	this->cells = new CellType[this->GetSize()];
	this->baggagePositions.clear();
	int x = 0;
	int y = 0;
	for (char& cell : data) {
		if (cell == '\n') {
			++y;
			x = 0;
			continue;
		}

		CellType type = GetCellType(cell);
		if (type == CellType::PLAYER) {
			this->SetFloor(x, y, CellType::CEILING);
			playerPosition.SetX(x);
			playerPosition.SetY(y);
		}
		else if (type == CellType::BAGGAGE) {
			this->SetFloor(x, y, CellType::CEILING);
			this->baggagePositions.push_back(Position(x, y));
		}
		else {
			this->SetFloor(x, y, type);
		}
		++x;
	}
}

StageData::~StageData() {
	delete[] cells;
}

CellType StageData::GetCellType(const char cell) {
	switch (cell) {
	case '#':return CellType::WALL;
	case ' ':return CellType::CEILING;
	case '.':return CellType::GOAL;
	case 'o':return CellType::BAGGAGE;
	case 'p':return CellType::PLAYER;
	default:return CellType::WALL;
	}
}

int StageData::GetSize() {
	return this->width * this->height;
}