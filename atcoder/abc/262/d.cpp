#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i <= (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui N;
    cin >> N;
    vector<ui> a(N);
    for (ui ai : a) cin >> ai;

    /** 同値類[i][j]: a[k] % i == j となる a[k] の個数 */
    vector<vector<ui>> 同値類(N + 1);
    REP1(i, N) {
        同値類[i].resize(i, 0);
        REP(j, N) { ++同値類[i][a[j] % i]; }
    }

    for (auto v : 同値類) {
        for (ui cnt : v) {
        }
    }

    return 0;
}
