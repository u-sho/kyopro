#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<uint> C(N);
    for (uint &Ci : C) cin >> Ci;

    vector<uint> last_color(M + 1);
    for (uint i = 0; i < N; i++) {
        last_color[C[i]] = i;  // 色Ciの最後尾
    }

    /* 直前の同じ色(循環index) */
    vector<uint> before_color(N);
    for (uint i = 0; i < N; i++) {
        before_color[i]  = last_color[C[i]];
        last_color[C[i]] = i;  // 色Ciのi以下の最後尾
    }

    for (uint i = 0; i < N; i++) {
        cout << S[before_color[i]];
    }
    cout << "\n";

    return 0;
}
