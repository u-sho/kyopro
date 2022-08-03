#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;

    size_t lenS = S.length(), lenT = T.length();
    if (lenS * lenT < 1'0000'0000UL) {
        size_t ans = lenT;
        REP(i, lenS - lenT + 1) {
            size_t dif_count = 0UL;
            REP(j, lenT) {
                if (S[i + j] != T[j]) ++dif_count;
            }
            ans = min(ans, dif_count);
        }
        cout << ans << "\n";
        return 0;
    }

    return 0;
}
