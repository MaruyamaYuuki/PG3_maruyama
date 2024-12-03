#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
// 実行順序を管理する変数
int turn = 1; 

void Num1(int num) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return turn == 1; });
    num += 1;
    printf("thread %d\n", num);
    turn = 2;
    cv.notify_all();
}

void Num2(int num) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return turn == 2; });
    num += 2;
    printf("thread %d\n", num);
    turn = 3;
    cv.notify_all();
}

void Num3(int num) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return turn == 3; }); 
    num += 3;
    printf("thread %d\n", num);
    turn = 1;
    cv.notify_all();
}

int main() {
	int num = 0;

	std::thread th1(Num1, num);
	std::thread th2(Num2, num);
	std::thread th3(Num3, num);

	th1.join();
	th2.join();
	th3.join();

	return 0; 
}