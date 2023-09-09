#include <bits/stdc++.h>
using namespace std;

#define ALL(v)   (v).begin(), (v).end()
#define SORT(v)  sort(ALL(v))
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

vector<pair<size_t, size_t>> v_ij = {
    {0, 0},
    {0, 1},
    {0, 2},

    {1, 0},
    {1, 1},
    {1, 2},

    {2, 0},
    {2, 1},
    {2, 2}
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> c(3);
    for (auto &ci : c) cin >> ci;

    do {
        set<map<pair<size_t, size_t>, char>> lines = {
            {{{0, 0}, '-'}, {{0, 1}, '-'}, {{0, 2}, '-'}},
            {{{1, 0}, '-'}, {{1, 1}, '-'}, {{1, 2}, '-'}},
            {{{2, 0}, '-'}, {{2, 1}, '-'}, {{2, 2}, '-'}},

            {{{0, 0}, '-'}, {{1, 0}, '-'}, {{2, 0}, '-'}},
            {{{0, 1}, '-'}, {{1, 1}, '-'}, {{2, 1}, '-'}},
            {{{0, 2}, '-'}, {{1, 2}, '-'}, {{2, 2}, '-'}},

            {{{0, 0}, '-'}, {{1, 1}, '-'}, {{2, 2}, '-'}},
            {{{0, 2}, '-'}, {{1, 1}, '-'}, {{2, 0}, '-'}}
        };

        for (const auto &ij : v_ij) {
            vector<decltype(lines)::iterator> delete_lines;
            for (auto it = lines.begin(); it != lines.end(); it++) {
                if (!(*it).contains(ij)) continue;

                uint8_t count = 0;
                char known_c  = '-';
                for (auto &[ij_c, cc] : *it) {
                    if (cc == '-') count++;
                    else known_c = cc;
                }
                if (known_c == c[ij.first][ij.second]) goto END_LOOP;
                else delete_lines.push_back(it);
            }

            for (auto it : delete_lines) {
                lines.erase(it);
            }
        }
    END_LOOP:
    } while (next_permutation(ALL(v_ij)));  // 9! = 36288

    return 0;
}
