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

    unsigned N, D, W;  // <= 2 * 10^5
    cin >> N >> D >> W;

    vector<pair<unsigned, unsigned>> TX(N);
    for (auto &[Ti, Xi] : TX) cin >> Ti >> Xi;
    ranges::sort(TX);  // 時刻順にソート

    vector<unsigned> min_before_D(N,
                                  0U);  // D秒後よりあとのXで最小のインデックス
    for (unsigned i = 0; i < N; i++) {
        while (min_before_D[i] < N &&
               TX[min_before_D[i]].first <= TX[i].first + D)
            min_before_D[i]++;
        if (i + 1 < N) min_before_D[i + 1] = min_before_D[i];
    }

    return 0;
}
