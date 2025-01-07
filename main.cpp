#include <cstdio>
#include <string>
#include <chrono>

void CopyTime(const std::string& src) {
    auto start = std::chrono::high_resolution_clock::now(); 
    std::string dest = src; 
    // コピー
    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
    printf("コピー: %lld ns\n", duration); 
}

void MoveTime(std::string&& src) {
    auto start = std::chrono::high_resolution_clock::now(); 
    std::string dest = std::move(src); 
    // 移動 
    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
    printf("移動: %lld ns\n", duration); 
}

int main() {
    std::string a(10000, 'a'); // 10,000文字の文字列を作成

    printf("100,000文字を移動とコピーで比較\n");
    CopyTime(a);       // コピー時間を計測
    MoveTime(std::move(a)); // 移動時間を計測

    return 0;
}

