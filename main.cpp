#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


typedef void(*PFunc)(bool);

/*void DispResult(int* s) {
	printf("%d秒待って実行されたよ\n", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p(&second);
}*/

void DispResult(bool isCorrect) {
	if (isCorrect) {
		printf("正解\n");
	}
	else {
		printf("不正解\n");
	}
}

void RollDiceAndJudge(PFunc p, int choice) {
	// サイコロを振る
	int diceRoll = rand() % 6 + 1;

	// サイコロの出目が奇数か偶数かを判定
	bool isEven = (diceRoll % 2 == 0);

	// ユーザーの選択が奇数か偶数かをチェック(1 : 奇数 2 : 偶数)
	bool choiceEven = (choice == 2);

	int second = 3;

	Sleep(second * 1000);
	DispResult(choiceEven == isEven);
	printf("サイコロの出目 : %d", diceRoll);
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	PFunc p;
	p = DispResult;
	int choice;

	printf("サイコロを振ります。奇数(1)か偶数(2)か当ててください: ");
	scanf_s("%d", &choice);

	if (choice != 1 && choice != 2) {
		printf("無効な入力です\n");
		return 1;
	}

	RollDiceAndJudge(p, choice);

	return 0;
}