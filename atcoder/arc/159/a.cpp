#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint64_t N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    for (vector<int> &A_i : A)
        for (int &a_ij : A_i) cin >> a_ij;

    REP(c, N + 1) {
        REP(i, N) {
            REP(j, N) {
                if (A[i][j] == 0) continue;
                REP(k, N) {
                    if (A[j][k] == 0) continue;
                    if (A[i][k] == 0) A[i][k] = A[i][j] + A[j][k];
                    else A[i][k] = min(A[i][k], A[i][j] + A[j][k]);
                }
            }
        }
    }
    REP(i, N) {
        REP(j, N) {
            if (A[i][j] == 0) A[i][j] = -1;
            // cout << A[i][j];
        }
        // cout << "\n";
    }

    uint16_t Q;
    cin >> Q;
    while (Q--) {
        uint64_t s, t;
        cin >> s >> t;
        cout << A[(s - 1) % N][(t - 1) % N] << "\n";
    }

    return 0;
}
