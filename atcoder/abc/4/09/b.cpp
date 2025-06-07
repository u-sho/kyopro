#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;  // <= 100
    cin >> N;
    vector<uint> A(N);  // Ai <= 1e9
    for (uint &Ai : A) cin >> Ai;

    ranges::sort(A);
    uint x = 0;
    for (uint i = 0; i < N; i++) {
        if (N - i < A[i]) x = max(x, N - i);
        if (N - i >= A[i]) x = max(x, A[i]);
    }
    cout << x << '\n';

    return 0;
}
