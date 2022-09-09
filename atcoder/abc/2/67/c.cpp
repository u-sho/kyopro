#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define REP(i, n) for (long long i = 0; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (long long &Ai : A) cin >> Ai;

    vector<long long> partial_sum_A(N + 1, 0LL);
    partial_sum(ALL(A), next(partial_sum_A.begin()));

    long long sumB = 0;
    REP(i, M) sumB += (i + 1LL) * A[i];
    long long ans = sumB;
    REP(i, N - M) {
        sumB -= partial_sum_A[i + M] - partial_sum_A[i];
        sumB += ((long long)M) * A[i + M];
        ans = max(ans, sumB);
    }

    cout << ans << '\n';

    return 0;
}
