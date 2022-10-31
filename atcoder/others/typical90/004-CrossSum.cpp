#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (uint i = 0U; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint H, W;
    cin >> H >> W;
    vector<vector<uint>> A(H, vector<uint>(W));
    for (auto& Ai : A)
        for (auto& Aij : Ai) cin >> Aij;

    vector<uint> sum_row(H, 0), sum_col(W, 0);
    REP(i, H) REP(j, W) {
        sum_row[i] += A[i][j];
        sum_col[j] += A[i][j];
    }

    REP(i, H) {
        REP(j, W) {
            cout << sum_row[i] + sum_col[j] - A[i][j];
            if (j != W - 1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
