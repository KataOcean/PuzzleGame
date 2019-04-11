#pragma once

#include "CellType.h"
#include "StageData.h"

class Stage {
private:
	StageData *stageData;
public:
	Stage(const char *fileName);
	~Stage();

	CellType GetFloor(int x, int y) {
		return this->stageData->GetFloor(x, y);
	}

	Position GetPlayerPosition() {
		return this->stageData->GetPlayerPosition();
	}

	vector<Position> GetBaggagePositions() {
		return this->stageData->GetBaggagePositions();
	}

	int GetWidth() {
		return this->stageData->GetWidth();
	}
	
	int GetHeight() {
		return this->stageData->GetHeight();
	}
};