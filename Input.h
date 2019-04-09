#pragma once

enum Keys {
	UP_KEY,
	DOWN_KEY,
	LEFT_KEY,
	RIGHT_KEY,
	QUIT_KEY,
	KEYS_MAX
};

enum KeyState {
	NONE,
	PUSHED
};

class Input {
private:
	KeyState states[KEYS_MAX];
public:
	Input() {};
	void Update();

	KeyState GetKeyState(Keys key) { return states[key]; }
};