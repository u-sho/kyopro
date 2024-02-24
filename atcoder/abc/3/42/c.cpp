#include <bits/stdc++.h>

int main() {
    using std::cin;
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::vector<char> alphabetTransition;
    for (char c = 'a'; c <= 'z'; c++) {
        alphabetTransition.push_back(c);
    }

    uint N;
    cin >> N;
    std::string S;
    cin >> S;
    uint Q;
    cin >> Q;
    for (uint i = 0; i < Q; i++) {
        char ci, di;
        cin >> ci >> di;

        if (ci != di) {
            for (auto &alp : alphabetTransition) {
                if (alp == ci) {
                    alp = di;
                }
            }
        }
    }

    for (const auto &c : S) {
        std::cout << alphabetTransition[c - 'a'];
    }
    std::cout << '\n';

    return 0;
}
