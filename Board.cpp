#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() {
	this->stage = new Stage("Data/StageData.dat");

	this->player = new Player(this->stage->GetPlayerPosition());

	for (auto pos : this->stage->GetBaggagePositions()) {
		this->baggages.push_back(Baggage(pos));
	}
}

Board::~Board() {
	delete this->stage;
}

void Board::Update(Input input) {

	Direction direction = UP;

	if (input.GetKeyState(UP_KEY))direction = UP;
	else if (input.GetKeyState(DOWN_KEY))direction = DOWN;
	else if (input.GetKeyState(LEFT_KEY))direction = LEFT;
	else if (input.GetKeyState(RIGHT_KEY))direction = RIGHT;

	auto nextPosition = Position(this->player->GetX(), this->player->GetY());

	if (GetNextPosition(&nextPosition , direction) ){
		auto baggage = FindBaggage(nextPosition.GetX(), nextPosition.GetY());
		auto baggagePosition = Position(nextPosition.GetX(), nextPosition.GetY());
		if (baggage != NULL) {
			if (GetNextPosition(&baggagePosition, direction,true)) {
				baggage->Move(baggagePosition.GetX(), baggagePosition.GetY());
				this->player->Move(nextPosition.GetX(), nextPosition.GetY());
			}
		}
		else {
			this->player->Move(nextPosition.GetX(), nextPosition.GetY());
		}
	}

}

bool Board::CheckMovable(Position position , Direction direction, bool isBaggage) {
	if (this->stage->GetFloor(position.GetX(), position.GetY()) != WALL) {
		if (isBaggage) {
			auto baggage = FindBaggage(position.GetX(), position.GetY());
			return baggage == NULL;
		}
		return true;
	}
	return false;
}

bool Board::GetNextPosition(Position *position, Direction direction, bool isBaggage) {
	int x = position->GetX();
	int y = position->GetY();

	switch (direction)
	{
	case UP   :position->SetY(position->GetY() - 1); break;
	case DOWN :position->SetY(position->GetY() + 1); break;
	case RIGHT:position->SetX(position->GetX() + 1); break;
	case LEFT :position->SetX(position->GetX() - 1); break;
	}

	return CheckMovable(*position, direction,isBaggage);
}

bool Board::CheckClear() {
	for (auto &baggage : baggages) {
		if (this->stage->GetFloor(baggage.GetX(), baggage.GetY()) != GOAL) {
			return false;
		}
	}
	return true;
}

void Board::Draw() {
	for (int y = 0; y < this->stage->GetHeight(); ++y) {
		for (int x = 0; x < this->stage->GetWidth(); ++x){

			auto baggage = FindBaggage(x, y);
			if (baggage != NULL)cout << 'o';
			else if (x == this->player->GetX() && y == this->player->GetY()) {
				cout << 'p';
			}
			else {
				switch (this->stage->GetFloor(x, y)) {
				case WALL:cout << '#'; break;
				case CEILING:cout << ' '; break;
				case GOAL:cout << '.'; break;
				}
			}
		}
		cout << endl;
	}
}