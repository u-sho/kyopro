#include <iostream>
int main() {
    long long N, M;
    std::cin >> N >> M;
    if (N * 2LL >= M) {
        std::cout << M / 2LL << "\n";
        return 0;
    }
    std::cout << N + (M - 2LL * N) / 4LL << "\n";
    return 0;
}