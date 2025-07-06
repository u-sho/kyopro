#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint Q;
    cin >> Q;

    queue<pair<uint, uint>> A;
    for (uint q = 0; q < Q; q++) {
        uint query_type;
        cin >> query_type;

        if (query_type == 1) {
            uint c, x;
            cin >> c >> x;
            A.emplace(x, c);
        }

        if (query_type == 2) {
            uint k;
            cin >> k;
            uint64_t sum = 0;
            for (; !A.empty() && A.front().second <= k; A.pop()) {
                const auto [x, c] = A.front();

                sum += (uint64_t)x * (uint64_t)c;
                k   -= c;
            }
            if (k) {
                sum              += (uint64_t)A.front().first * (uint64_t)k;
                A.front().second -= k;
            }
            cout << sum << '\n';
        }
    }

    return 0;
}
