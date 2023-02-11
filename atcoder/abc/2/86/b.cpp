#include <iostream>
#include <string>

int main(void) {
    unsigned N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    for (unsigned i = 0; i + 1U < N; i++) {
        std::cout << S.at(i);
        if (S[i] == 'n' && S.at(i + 1U) == 'a') std::cout << 'y';
    }
    std::cout << S.at(N - 1U) << '\n';
    return 0;
}