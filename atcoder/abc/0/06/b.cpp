#include <iostream>
constexpr int mod = 10007;

int Tribonacci[1000006] = {0, 0, 0, 1, 1, 2, 4, 7, 13};

int mod_Triibonacci(int n) {
    if (n == 1 || n == 2) return 0;
    if (Tribonacci[n] != 0) return Tribonacci[n];

    int tn = mod_Triibonacci(n - 1) + mod_Triibonacci(n - 2) +
             mod_Triibonacci(n - 3);
    tn %= mod;

    Tribonacci[n] = tn;
    return tn;
}

int main(void) {
    int n;
    std::cin >> n;
    std::cout << mod_Triibonacci(n) << std::endl;
    return 0;
}