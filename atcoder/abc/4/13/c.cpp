#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define SORT(v)  std::ranges::sort(v)
#define ALL(v)   (v).begin(), (v).end()
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint Q;
    cin >> Q;

    deque<pair<uint, uint>> A;
    deque<pair<uint64_t, uint64_t>> psum_A;
    for (uint q = 0; q < Q; q++) {
        uint query_type;
        cin >> query_type;
        if (query_type == 1) {
            uint c, x;
            cin >> c >> x;
            A.push_back({x, c});

            uint64_t sum = (uint64_t)c * (uint64_t)x;
            if (psum_A.empty()) {
                psum_A.push_back({sum, c});
            } else {
                psum_A.push_back(
                    {psum_A.back().first + sum, psum_A.back().second + c});
            }
        }
        if (query_type == 2) {
            uint k;
            cin >> k;
            A.push_front(x);
        }
    }

    return 0;
}
