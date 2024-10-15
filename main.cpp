#include <stdio.h>
#include <functional>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef void (*PFunc)(bool);

void SetTimeout(PFunc p, int second, bool isJudge) {
	Sleep(second * 1000);

	p(isJudge);
}

void DispResult(bool isJudge) {
	if (isJudge) {
		printf("正解\n");
	}
	else {
		printf("不正解\n");
	}
}

void DiceJudge(PFunc p, int choice) {
	// サイコロを振る
	int dice = rand() % 6 + 1;

	// サイコロの出目が奇数か偶数かを判定
	bool isDiceRoll;
	if (dice % 2 == 0) {
		isDiceRoll = true;
	}
	else {
		isDiceRoll = false;
	}

	// ユーザーの選択が奇数か偶数かをチェック
	bool isUserChoice = (choice == 2);
	if (choice == 2) {
		isUserChoice = true;
	}
	else {
		isUserChoice = false;
	}

	int second = 3;
	bool result = (isUserChoice == isDiceRoll);

	SetTimeout(p, second, result);
	printf("サイコロの出目 : %d", dice);
}

int main(int argc, const char *argv[]) {
	// ダイスを振る(乱数の生成)
	unsigned int currentTime = time(nullptr);
	srand(currentTime);

	// 入力
	int choice;
	std::function<void()> fx = [&choice]() {
		while (true) {
	    	printf("半(奇数)か丁(偶数)か（半なら1、丁なら2）\n");
	    	scanf_s("%d", &choice);

			if (choice == 1 || choice == 2) {
				// 正しい入力
				break;
			}
			else {
				// 無効な入力の場合
				printf("もう一度入力してください。\n");
			}
		}
	};

	fx();
	PFunc p;
	p = DispResult;
	DiceJudge(p, choice);

	return 0;
}