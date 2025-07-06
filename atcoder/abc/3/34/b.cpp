#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int64_t A, L, R;
    uint M;
    cin >> A >> M >> L >> R;

    // 座標を正にする
    uint64_t a = A + 1'000'000'000'000'000'000ULL;
    uint64_t l = L + 1'000'000'000'000'000'000ULL;
    uint64_t r = R + 1'000'000'000'000'000'000ULL;

    // A <= L <= R とする．
    a %= M;
    if (l < a) {
        l += M;
        r += M;
    }

    // A = 0 とする．
    l -= a;
    r -= a;

    // L を次の M の倍数にする．
    if (l % M) {
        l += M - (l % M);
    }

    if (l > r) {
        cout << 0 << '\n';
    } else {
        // l = 0;
        r -= l;

        cout << (r / M + 1ull) << '\n';
    }

    return 0;
}
