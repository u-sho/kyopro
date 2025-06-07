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

    vector<uint> s(N);
    partial_sum(d.begin(), d.end(), s.begin());
    for (auto& si : s) si %= L;

    map<uint, uint> pos_count;
    for (const auto si : s) pos_count[si]++;

    ranges::sort(s);
    s.erase(unique(s.begin(), s.end()), s.end());

    uint count = 0;
    for (const auto si : s) {
        if (si >= L / 3u) break;

        uint sj = si + (L / 3u);
        uint sk = (sj + (L / 3u)) % L;

        count += pos_count[si] * pos_count[sj] * pos_count[sk];
    }

    cout << count << '\n';

    return 0;
}
