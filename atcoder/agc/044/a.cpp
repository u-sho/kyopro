#include <bits/stdc++.h>
using lli = long long;
// 定数
constexpr lli N_MAX = 1e18;
// メモ
std::map<lli, lli> solved;

lli N, A, B, C, D;
lli solve(lli n) {
    using std::min;
    if (n == 0) return 0;
    if (n == 1) return D;
    if (solved.count(n)) return solved.at(n);

    lli m2 = n % 2;
    lli M2 = n % 2;
    lli m3 = n % 3;
    lli M3 = (3 - (n % 3)) % 3;
    lli m5 = n % 5;
    lli M5 = (5 - (n % 5)) % 5;

    lli res = N_MAX;
    // 1でわる
    if (n < res / D) {  // overflow対策
        res = n * D;
    }

    // 2でわる
    res = min(res, m2 * D + solve((n - m2) / 2LL) + A);
    res = min(res, M2 * D + solve((n + M2) / 2LL) + A);

    // 3でわる
    res = min(res, m3 * D + solve((n - m3) / 3LL) + B);
    res = min(res, M3 * D + solve((n + M3) / 3LL) + B);

    // 5でわる
    res = min(res, m5 * D + solve((n - m5) / 5LL) + C);
    res = min(res, M5 * D + solve((n + M5) / 5LL) + C);

    // solved
    solved.insert(std::make_pair(n, res));
    return res;
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> A >> B >> C >> D;
        cout << solve(N) << endl;
        solved.clear();
    }
    return 0;
}