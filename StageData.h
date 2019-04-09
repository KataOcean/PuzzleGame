#pragma once

#include "Position.h"
#include <vector>

using namespace std;

class StageData {
private:
	Position playerPosition;
	vector<Position*> baggagePositions;
public:
	StageData(char fileName[1024]);
	~StageData();
};