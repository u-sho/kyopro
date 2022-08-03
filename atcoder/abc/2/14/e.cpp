#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        ui N;
        cin >> N;
        vector<pair<ui, ui>> LR(N);
        for (pair<ui, ui> &LRi : LR) cin >> LRi.first >> LRi.second;

        ui minL = UINT_MAX, maxR = 0;
        REP(i, N) {
            minL = min(minL, LR[i].first);
            maxR = max(maxR, LR[i].second);
        }
        if (maxR - minL + 1 < N) {
            cout << "no\n";
            continue;
        }

        REP(i, N) { if (LR[i].first == LR[i].second) }
    }

    return 0;
}
