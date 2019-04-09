#include "Player.h"

Player::Player(int _x , int _y) {
	this->position = new Position(_x, _y);
}

Player::~Player() {
	delete this->position;
}

void Player::Move(int _x, int _y) {
	this->position->SetX(_x);
	this->position->SetY(_y);
}