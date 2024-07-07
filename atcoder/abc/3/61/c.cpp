#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, K;
    cin >> N >> K;
    vector<uint> A(N);
    for (uint &Ai : A) cin >> Ai;

    ranges::sort(A);

    uint ans = A[N - 1] - A[0];
    for (uint i = 0; i <= K; i++) {
        ans = min(ans, A[N - 1 - K + i] - A[i]);
    }

    cout << ans << '\n';

    return 0;
}
