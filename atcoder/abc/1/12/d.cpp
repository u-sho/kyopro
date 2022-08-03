#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    for (int gcd = M / N; gcd > 0; --gcd) {
        if (M % gcd == 0) {  // ≡ M % (gcd*N) % gcd
            std::cout << gcd << '\n';
            return 0;
        }
    }

    return 1;
}