#include <bits/stdc++.h>
int main() {
    std::vector<unsigned> S;
    S.push_back(0);

    bool yes = true;
    for (unsigned i = 1; i <= 8; i++) {
        unsigned Si;
        std::cin >> Si;
        S.push_back(Si);

        if (S[i - 1] > Si) yes = false;
        if (100 > Si || Si > 675) yes = false;
        if (Si % 25) yes = false;
    }
    std::cout << (yes ? "Yes\n" : "No\n");
    return 0;
}