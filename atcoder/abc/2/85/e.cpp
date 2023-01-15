#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;

    // 累積和
    vector<uint64_t> A;
    A.push_back(0U);
    for (unsigned i = 1U; i <= N; i++) {
        uint64_t Ai;
        cin >> Ai;
        Ai += A.back();
        A.push_back(Ai);
    }


    // 両端が休日と仮定
    // dp[i]: i日与えられたときの生産量の最大値

    // 間に合わね
    cout << dp[N-1] << '\n';

    return 0;
}