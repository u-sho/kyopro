#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin >> N >> M;
    vector<uint> A(N);
    for (uint &Ai : A) cin >> Ai;

    ranges::sort(A);
    uint ans = 1U;
    uint r   = 0;
    for (uint l = 0; l < N; l++) {
        for (; r < N && A[r] < A[l] + M; r++)
            ;
        ans = max(ans, r - l);
        // cout << l << ": " << r << "\n";
    }

    cout << ans << "\n";
    return 0;
}
