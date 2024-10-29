#include <stdio.h>
#include "Chocolate.h"
#include "WhiteChoco.h"
#include "MilkChoco.h"
#include "BitterChoco.h"

int main() {
	Chocolate* choco[3];

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			choco[i] = new WhiteChoco;
		}
		else if (i == 1) {
			choco[i] = new MilkChoco;
		}
		else if (i == 2) {
			choco[i] = new BitterChoco;
		}
	}

	for (int i = 0; i < 3; i++) {
		choco[i]->DrawName();
	}

	for (int i = 0; i < 3; i++) {
		delete choco[i];
	}

	return 0;
}