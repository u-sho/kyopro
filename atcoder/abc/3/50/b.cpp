#include <bits/stdc++.h>
using namespace std;

vector<bool> takahashi(1023, true);
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, Q;
    cin >> N >> Q;
    vector<uint> T(Q);
    for (uint& Ti : T) cin >> Ti;

    for (const uint& Ti : T) {
        takahashi.at(Ti) = !takahashi.at(Ti);
    }

    uint count = 0U;
    for (uint i = 1U; i <= N; ++i) {
        if (takahashi.at(i)) ++count;
    }

    cout << count << '\n';

    return 0;
}
