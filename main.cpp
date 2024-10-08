#include <stdio.h>

int GeneralWages(int n) {
	int wages = 1072;
	return(wages * n);
}

int RecursiveWages(int n) {

	if (n == 1) {
		return(100);
	}

	return (RecursiveWages(n - 1) * 2 - 50);
}

void CompareWages(int n) {
	int rResult, gResult;
	rResult = RecursiveWages(n);
	gResult = GeneralWages(n);

	printf("%d時間働いた場合\n一般的な資金体系 : %d\n再帰的な資金体系 : %d\n\n", n, gResult, rResult);
}

int main() {
	int n = 12;
	for (int i = 1; i <= n; i++) {
        CompareWages(i);
	}



	return 0;
}