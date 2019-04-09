#pragma once

#include "Input.h"
#include "Stage.h"
#include "Player.h"
#include "Baggage.h"
#include "Direction.h"
#include <vector>

using namespace std;

class Board {
private:
	Stage *stage;
	Player *player;
	vector<Baggage*> baggages;
public:
	Board();
	~Board();

	void Update(Input input);
	void Draw();

	bool CheckMovable(Position position, Direction direction, bool isBaggage = false);
	bool GetNextPosition(Position *position, Direction direction, bool isBaggage = false);
	bool CheckClear();

	Baggage *FindBaggage(int _x, int _y) {
		for (auto &baggage : baggages) {
			if (_x == baggage->GetX() && _y == baggage->GetY()) {
				return baggage;
			}
		}
		return NULL;
	}
};