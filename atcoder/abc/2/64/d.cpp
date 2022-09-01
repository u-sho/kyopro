#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const string atcoder = "atcoder";

    string S;
    std::cin >> S;

    uint ans = 0;
    REP(i, 7) {
        auto p = S.find(atcoder[i]);
        for (auto j = p; i != j; j--) {
            swap(S[j], S[j - 1]);
            ans++;
        }
    }

    std::cout << ans << "\n";

    return 0;
}
