#include <iostream>
#include "GameManager.h"
#include "GameState.h"
using namespace std;

int main() {
	GameManager *gm = new GameManager();

	while (true) {
		gm->GetInput();
		if (gm->Update() == 1) {
			if (gm->GetState() == CLEARED) {
				cout << "Congraturations!";
			}
			break;
		}
		gm->Draw();
	}

	delete gm;

	return 0;
}