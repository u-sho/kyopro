#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, L;  // <= 3e5
    cin >> N >> L;

    if (L % 3u) {
        cout << 0 << '\n';
        return 0;
    }

    vector<uint> d(N, 0);  // <= L
    for (uint i = 1; i <= N - 1; i++) cin >> d[i];

    map<uint, uint> pos_count;
    uint pos = 0;
    for (const uint di : d) {
        pos = (pos + di) % L;
        pos_count[pos]++;
    }

    uint count = 0;
    for (uint p1 = 0; p1 < L / 3u; p1++) {
        const uint p2 = (p1 + (L / 3u)) % L;
        const uint p3 = (p2 + (L / 3u)) % L;

        count += pos_count[p1] * pos_count[p2] * pos_count[p3];
    }

    cout << count << '\n';

    return 0;
}
