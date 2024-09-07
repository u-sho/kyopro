#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<vector<uint>> A(N);
    for (uint i = 0; i < N; i++) {
        for (uint j = 0; j <= i; j++) {
            uint Aij;
            cin >> Aij;
            A[i].push_back(Aij);
        }
    }

    uint 元素 = 1;
    for (uint i = 0; i < N; i++) {
        uint Mi = max(元素 - 1, i);
        uint mi = min(元素 - 1, i);
        元素    = A[Mi][mi];
    }

    cout << 元素 << '\n';

    return 0;
}
