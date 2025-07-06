#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin >> N >> M;
    uint sum_A = 0;
    for (uint i = 1; i <= N; i++) {
        uint Ai;
        cin >> Ai;
        sum_A += Ai;
    }
    cout << ((sum_A <= M) ? "Yes\n" : "No\n");

    return 0;
}
