#include "GameManager.h"
#include <iostream>
using namespace std;

GameManager::GameManager() {
	this->input = new Input();
	this->board = new Board();
	this->state = INIT;
}

GameManager::~GameManager() {
	delete this->input;
	delete this->board;
}

void GameManager::GetInput() {
	if ( this->state == MAIN || this->state == CLEARED)	this->input->Update();
}

int GameManager::Update() {

	switch (this->state)
	{
	case INIT:
		this->state = MAIN;
		break;
	case MAIN:
		if (this->input->GetKeyState(QUIT_KEY))this->state = QUIT;
		this->board->Update(*this->input);
		if (this->board->CheckClear())this->state = CLEARED;
		break;
	case CLEARED:
		return 1;
		break;
	case QUIT:
		return 1;
		break;
	default:
		return -1;
	}


	return 0;
}

void GameManager::Draw() {

	switch (this->state)
	{
	case MAIN:
		this->board->Draw();
		cout << "Please input next action" << endl;
		cout << "w:ª a:© s:« d:¨ q:quit" << endl;
		break;
	case CLEARED:
		this->board->Draw();
		cout << "Congratulations!" << endl;
		cout << "Please input any key" << endl;
		break;
	default:
		break;
	}
}