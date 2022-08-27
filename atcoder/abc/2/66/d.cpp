#include <bits/stdc++.h>
using namespace std;

using ulli = unsigned long long;

#define ALL(v) (v).begin(), (v).end()

#define REP(i, n) for (ulli i = 0UL; i < (n); i++)
#define REP1(i, n) for (ulli i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ulli N;
    cin >> N;
    vector<ulli> T, X, A;
    REP(i, N) {
        ulli Ti, Xi, Ai;
        cin >> Ti >> Xi >> Ai;
        T.push_back(Ti);
        X.push_back(Xi);
        A.push_back(Ai);
    }

    if (N == 1) {
        if (T[0] < X[0]) {
            cout << "0\n";
        } else {
            cout << A[0] << "\n";
        }
        return 0;
    }

    // dp[i][j] := 時刻T[i]に高橋君が座標jにいるまでに捕まえた総和の最大
    vector<vector<ulli>> dp(N + 1, vector<ulli>(5, 0));

    REP(i, 5) {
        if (T[0] < i) break;
        if (X[0] == i) {
            dp[0][i] = A[0];
        }
    }

    REP1(i, N) {
        // REP(j, 5) cout << dp[i - 1][j] << ' ';
        // cout << '\n';
        const ulli dT = T[i] - T[i - 1];
        REP(j, 5) {
            if (T[i] < j) break;
            const ulli b = (dT < j) ? (j - dT) : 0;
            const ulli e = (j + dT < 5U) ? (4U - j - dT) : 0;
            const ulli maxTi1 = *max_element(next(dp[i - 1].begin(), b),
                                             prev(dp[i - 1].end(), e));
            dp[i][j] = maxTi1;
            if (X[i] == j) {
                dp[i][j] += A[i];
            }
        }
    }

    cout << *max_element(ALL(dp[N - 1])) << "\n";

    return 0;
}
