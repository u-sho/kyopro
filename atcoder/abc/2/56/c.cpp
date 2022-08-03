#include <bits/stdc++.h>
using namespace std;

using ui = int;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define REP(i, n) for (ui i = 0U; i <= (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ui> h(3);
    for (ui &hi : h) cin >> hi;
    vector<ui> w(3);
    for (ui &wi : w) cin >> wi;

    for (ui &hi : h) hi -= 3u;
    for (ui &wj : w) wj -= 3u;
    SORT(h);
    SORT(w);

    ui ans = 0u;
    /**
     *      w0 < w1 < w2
     *    ----------------
     * h0 |  i |  j | *s |
     * ^  ----------------
     * h1 |  k |  l | *t |
     * ^  ----------------
     * h2 | *u | *v | *  |
     *    ----------------
     */
    REP(i, min(h[0], w[0])) {
        REP(j, min(h[0] - i, w[1])) {
            ui s = h[0] - i - j;
            if (s > w[2]) continue;

            REP(k, min(h[1], w[0] - i)) {
                ui u = w[0] - i - k;
                if (u > h[2]) continue;

                REP(l, min(h[1] - k, w[1] - j)) {
                    ui t = h[1] - k - l;
                    ui v = w[1] - j - l;
                    if (s + t > w[2]) continue;
                    if (u + v > h[2]) continue;
                    if (w[2] - s - t != h[2] - u - v) continue;

                    ++ans;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
