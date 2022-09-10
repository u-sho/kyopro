#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (long long &Ai : A) cin >> Ai;

    // dp[i][j] := i番目までの要素からj個選んだときの最大値
    vector<vector<long long>> dp(N, vector<long long>(M + 1U, LONG_LONG_MIN));
    dp[0][0] = 0LL;
    dp[0][1] = A[0];
    for (uint i = 1U; i < N; i++) {
        dp[i][0] = 0LL;
        for (uint j = 1U; j <= min(i + 1U, M); j++) {
            dp[i][j] =
                max(dp[i - 1][j], dp[i - 1][j - 1] + ((long long)j) * A[i]);
        }
    }

    cout << dp[N - 1][M] << '\n';
    return 0;
}
