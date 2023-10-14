#include <bits/stdc++.h>
using namespace std;

#define ALL(v)   (v).begin(), (v).end()
#define SORT(v)  sort(ALL(v))
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    string S;
    cin >> S;

    SORT(S);

    // sqrt(9'999'999'999'999) = 3'162'277.6601...
    uint ans = 0U;
    REP(i, 3'162'277ULL) {
        string sq = to_string(i * i);
        if (sq.length() > N) break;
        while (sq.length() < N) {
            sq.push_back('0');
        }
        SORT(sq);
        if (sq == S) ++ans;
    }

    cout << ans << "\n";

    return 0;
}
