#include <iostream>
int main() {
    unsigned long long A, B;
    std::cin >> A >> B;
    std::cout << (A + B - 1ULL) / B << '\n';
    return 0;
}