#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<int64_t> A(N);
    for (int64_t& Ai : A) cin >> Ai;

    int64_t 最小乗客数 = 0LL;
    int64_t 現在乗客数 = 0LL;  // 仮定
    for (const int64_t& Ai : A) {
        現在乗客数 += Ai;
        最小乗客数  = min(最小乗客数, 現在乗客数);
    }
    cout << (現在乗客数 - 最小乗客数) << '\n';

    return 0;
}
