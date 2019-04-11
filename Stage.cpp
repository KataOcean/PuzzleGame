#include "Stage.h"

Stage::Stage(const char* fileName) {
	this->stageData = new StageData(fileName);
}

Stage::~Stage() {
	delete this->stageData;
}
