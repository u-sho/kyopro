#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (uint i = 0U; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<uint> inv_P(N + 1U);
    REP(i, N) {
        uint Pi;
        cin >> Pi;
        inv_P[Pi] = i;
    }

    uint Q;
    cin >> Q;
    REP(i, Q) {
        uint Ai, Bi;
        cin >> Ai >> Bi;
        if (inv_P[Ai] < inv_P[Bi]) cout << Ai << '\n';
        else cout << Bi << '\n';
    }

    return 0;
}
