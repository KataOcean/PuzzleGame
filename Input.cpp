#include "Input.h"
#include <iostream>
using namespace std;

void Input::Update() {

	for (int i = 0; i < KEYS_MAX; ++i) {
		states[i] = NONE;
	}

	char c;
	cin >> c;
	
	switch (c) {
	case 'w': states[UP_KEY] = PUSHED; break;
	case 'a': states[LEFT_KEY] = PUSHED; break;
	case 's': states[DOWN_KEY] = PUSHED; break;
	case 'd': states[RIGHT_KEY] = PUSHED; break;
	case 'q': states[QUIT_KEY] = PUSHED; break;
	}
}