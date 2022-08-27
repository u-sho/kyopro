#include <bits/stdc++.h>
using namespace std;

using ulli = unsigned long long;

#define ALL(v) (v).begin(), (v).end()
#define REP(i, n) for (ulli i = 0UL; i < (n); i++)

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

    // dp[i][j] := 時刻iに高橋君が座標jにいるまでに捕まえた総和の最大
    vector<vector<ulli>> dp(1e5 + 1, vector<ulli>(5, 0));

    for (ulli i = T[0], k = 0U; i <= T[N - 1]; i++) {
        REP(j, 5) {
            dp[i][j] = dp[i - 1][j];
            if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if (j < 4) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
        }
        // REP(j, 5) cout << dp[i - 1][j] << ' ';
        // cout << '\n';
        if (T[k] == i) {
            // cout << k << '\n';
            if (T[k] >= X[k]) dp[i][X[k]] += A[k];
            k++;
        }
    }

    cout << *max_element(ALL(dp[T[N - 1]])) << "\n";

    return 0;
}
