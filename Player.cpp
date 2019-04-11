#include "Player.h"

Player::Player(int _x , int _y) {
	this->position.SetX(_x);
	this->position.SetY(_y);
}

Player::Player(const Position position)
{
	this->position = position;
}

Player::~Player() {
}

void Player::Move(int _x, int _y) {
	this->position.SetX(_x);
	this->position.SetY(_y);
}