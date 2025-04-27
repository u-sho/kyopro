#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<uint> A(N);
    for (uint &Ai : A) cin >> Ai;

    uint sum = 0;
    for (uint i = 0; i < N; i += 2) sum += A[i];

    cout << sum << '\n';

    return 0;
}
