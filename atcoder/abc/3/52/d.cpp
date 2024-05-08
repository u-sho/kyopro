#include <climits>
#include <iostream>
using namespace std;

#include <atcoder/segtree>
using atcoder::segtree;

[[nodiscard]] uint umin(uint a, uint b) { return std::min(a, b); }
[[nodiscard]] uint umax(uint a, uint b) { return std::max(a, b); }
[[nodiscard]] uint UMIN(void) { return 0U; }
[[nodiscard]] uint UMAX(void) { return UINT_MAX; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, K;
    cin >> N >> K;
    vector<uint> P(N);
    for (uint &Pi : P) cin >> Pi;

    segtree<uint, umin, UMAX> inv_minP(N);
    segtree<uint, umax, UMIN> inv_maxP(N);
    for (uint i = 0; i < N; i++) {
        inv_minP.set(P[i] - 1, i);
        inv_maxP.set(P[i] - 1, i);
    }

    uint ans = UMAX();
    for (uint a = 0; a <= N - K; a++) {
        ans = min(ans, inv_maxP.prod(a, a + K) - inv_minP.prod(a, a + K));
    }
    cout << ans << '\n';

    return 0;
}
