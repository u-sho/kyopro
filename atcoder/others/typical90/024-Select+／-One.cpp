#include <bits/stdc++.h>
using namespace std;

using ullong = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, K;
    cin >> N >> K;

    vector<uint> A(N), B(N);
    for (auto& Ai : A) cin >> Ai;
    for (auto& Bi : B) cin >> Bi;

    ullong sub_AB = 0ULL;
    for (uint i = 0U; i < N; i++) sub_AB += max(A[i], B[i]) - min(A[i], B[i]);

    if (sub_AB <= K && (K - sub_AB) % 2 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
