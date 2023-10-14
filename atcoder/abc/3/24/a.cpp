#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<uint> A(N);
    for (uint &Ai : A) cin >> Ai;

    for (uint i = 1; i < N; i++) {
        if (A[0] != A[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
