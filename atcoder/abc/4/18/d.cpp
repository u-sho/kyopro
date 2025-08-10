#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    string T;
    cin >> T;

    if (N == 1) {
        cout << T << '\n';
        return 0;
    }

    // 0の個数が奇数なら0,偶数なら1
    vector<uint> pT(N, 0);
    if (T[0] == '1') pT[0] = 1;
    for (uint i = 1; i < N; i++) {
        if (pT[i-1] == 0 && T[i] == '0') pT[i] = 1;
        if (pT[i-1] == 1 && T[i] == '1') pT[i] = 1;
    }

    // ppT[i]: 0の個数が偶数の接頭辞 T[0, j] j<=i の個数
    vector<uint> ppT(N, 0);
    partial_sum(pT.begin(), pT.end(), ppT.begin());

    uint64_t ans = ppT[N-1];
    for (uint i=1; i<N; i++) {
        if (pT[i] == pT[0]) ans += ppT[N-1] - ppT[i];
        else ans += (N - i) 
    }


    return 0;
}
