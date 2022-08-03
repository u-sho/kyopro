#include <bits/stdc++.h>
using namespace std;

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;
    vector<pair<int, int>> xy(N);
    for (pair<int, int> &xyi : xy) cin >> xyi.first >> xyi.second;

    sort(xy.begin(), xy.end());

    for (unsigned i = 0u; i < N; i++) {
        for (unsigned j = i + 1u; j < N; j++) {
            for (unsigned k = j + 1u; k < N; k++) {
                if ((xy[k].second - xy[j].second) *
                        (xy[j].second - xy[i].second) <
                    0)
                    continue;

                unsigned dx_ij = xy[j].first - xy[i].first;
                unsigned dy_ij = abs(xy[j].second - xy[i].second);

                unsigned dx_jk = xy[k].first - xy[j].first;
                unsigned dy_jk = abs(xy[k].second - xy[j].second);

                if (!dx_ij || !dy_ij || !dx_jk || !dy_jk) {
                    if (dx_ij == dx_jk && dy_ij == dy_jk) {
                        cout << "Yes\n";
                        return 0;
                    }
                    continue;
                }

                unsigned gcd_ij = gcd(dx_ij, dy_ij);
                dx_ij /= gcd_ij;
                dy_ij /= gcd_ij;

                unsigned gcd_jk = gcd(dx_jk, dy_jk);
                dx_jk /= gcd_jk;
                dy_jk /= gcd_jk;

                if (dx_ij == dx_jk && dy_ij == dy_jk) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";

    return 0;
}
