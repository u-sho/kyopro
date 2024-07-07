#import <iostream>
#import <vector>
int main() {
    uint N, K, X;
    std::cin >> N >> K >> X;
    std::vector<uint> A(N);
    for (uint &Ai : A) std::cin >> Ai;

    for (uint i = 0; i < N; i++) {
        if (i) std::cout << ' ';
        std::cout << A[i];
        if (i == K - 1U) std::cout << ' ' << X;
    }
    std::cout << '\n';
    return 0;
}