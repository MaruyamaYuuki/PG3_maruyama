#include <stdio.h>
#include "Enemy.h"

int main() {
	Enemy* enemy = nullptr;
	enemy = new Enemy();

	enemy->Update();

	delete enemy;
	return 0;
}