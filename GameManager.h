#pragma once

#include "Input.h"
#include "Board.h"
#include "GameState.h"

class GameManager {
private:
	Input *input;
	Board *board;
	GameState state;
public:
	GameManager();
	~GameManager();

	void GetInput(void);
	int Update(void);
	void Draw(void);

	GameState GetState() { return this->state; }
};