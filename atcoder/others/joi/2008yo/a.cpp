#include <iostream>
using namespace std;

int main(void) {
    unsigned 太郎君が支払う金額;  // 1以上1000未満の整数
    std::cin >> 太郎君が支払う金額;

    unsigned お釣り = 1000U - 太郎君が支払う金額;
    unsigned お釣りの枚数 = 0U;
    if (お釣り >= 500U) {
        お釣りの枚数 += お釣り / 500U;
        お釣り %= 500U;
    }
    if (お釣り >= 100U) {
        お釣りの枚数 += お釣り / 100U;
        お釣り %= 100U;
    }
    if (お釣り >= 50U) {
        お釣りの枚数 += お釣り / 50U;
        お釣り %= 50U;
    }
    if (お釣り >= 10U) {
        お釣りの枚数 += お釣り / 10U;
        お釣り %= 10U;
    }
    if (お釣り >= 5U) {
        お釣りの枚数 += お釣り / 5U;
        お釣り %= 5U;
    }
    if (お釣り >= 1U) {
        お釣りの枚数 += お釣り / 1U;
        お釣り %= 1U;
    }
    std::cout << お釣りの枚数 << '\n';
    return 0;
}