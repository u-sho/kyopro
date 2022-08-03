#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

#define REP1(i, n) for (ui i = 1UL; i <= (n); i++)

ulli combination(ulli n, ui r) {
    if (n < r) return 0ULL;
    if (n == r || r == 0) return 1ULL;
    if (n - r < r) return combination(n, n - r);
    ulli ans = 1ULL;
    for (ulli k = 1ULL; k <= r;) {
        ans *= n--;
        ans /= k++;
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui N;
    cin >> N;
    vector<ui> a(N + 1U);
    REP1(i, N) cin >> a[i];

    ui same_count = 0U;
    vector<bool> isSame(N + 1U, false);
    REP1(i, N) {
        if (a[i] == i) {
            isSame[i] = true;
            ++same_count;
        }
    }

    ulli ans = combination(same_count, 2U);
    REP1(i, N) {
        if (isSame[i]) continue;
        if (a[a[i]] == i) {
            ++ans;
            isSame[i] = isSame[a[i]] = true;
        }
    }

    cout << ans << endl;

    return 0;
}
