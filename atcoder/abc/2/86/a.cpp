#include <iostream>
#include <vector>

int main(void) {
    unsigned N, P, Q, R, S;
    std::cin >> N >> P >> Q >> R >> S;

    std::vector<unsigned> A(N);
    for (unsigned &Ai : A) std::cin >> Ai;

    for (unsigned i = 1; i <= N; i++) {
        if (P <= i && i <= Q)
            std::cout << A.at(i + R - P - 1U);
        else if (R <= i && i <= S)
            std::cout << A.at(i - R + P - 1U);
        else
            std::cout << A.at(i - 1U);

        if (i < N)
            std::cout << ' ';
        else
            std::cout << '\n';
    }
    return 0;
}