#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define SORT(v)  std::ranges::sort(v)
#define ALL(v)   (v).begin(), (v).end()
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    string S, T;
    cin >> N;
    cin >> S;
    cin >> T;

    // 文字数チェック
    uint B_in_S = 0;
    uint B_in_T = 0;
    for (uint i = 0; i < N; i++) {
        if (S[i] == 'B') B_in_S++;
        if (T[i] == 'B') B_in_T++;
    }
    if (B_in_S != B_in_T) {
        cout << "-1\n";
        return 0;
    }

    // 空きマスの追加
    S += "..";
    T += "..";

    for (uint i = 1; i < N; i++) {
        S[i] ^= S[N + 1] ^= S[i];
        S[N] ^= S[i - 1] ^= S[N];
    }

    // N=3
    // S0 S1 S2 . .
    // T0 T1 T2 . .

    // dp[i][j][k]
    // 101010
    // 101..001
    // ..110001
    // ....000111

    return 0;
}
