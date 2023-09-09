#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint_fast32_t N, M;
    cin >> N >> M;
    vector<uint_fast32_t> L(N);
    for (uint_fast32_t& Li : L) cin >> Li;

    uint_fast64_t l = *max_element(ALL(L));
    uint_fast64_t r = reduce(ALL(L), uint_fast64_t(N - 1U));  // 空白が N-1 個
    while (l < r) {
        uint_fast64_t c = l + (r - l) / 2U;

        uint_fast32_t line   = 1;
        uint_fast64_t cursor = L.front();
        REP1(i, N) {
            if (cursor + 1U + L[i] <= c) cursor += 1U + L[i];
            else {
                ++line;
                cursor = L[i];
            }
        }

        if (line <= M) r = c;
        else l = c + 1U;
    }

    cout << r << '\n';

    return 0;
}
