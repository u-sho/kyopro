#include <bits/stdc++.h>
using namespace std;

using c_t    = uint_fast8_t;
using c_it_t = uint_fast8_t;

const vector<tuple<c_it_t, c_it_t, c_it_t>> lines = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},

    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},

    {0, 4, 8},
    {2, 4, 6}
};

// o_ij[i] := マス i を何番目に開けるか
array<c_it_t, 9> o_ij = {0, 1, 2, 3, 4, 5, 6, 7, 8};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    array<c_t, 9> c;
    for (auto &cij : c) cin >> cij;

    uint_fast32_t gakkari_count = 0U;
    do {
        for (const auto &[l0, l1, l2] : lines) {
            c_t c0 = c[l0], c1 = c[l1], c2 = c[l2];
            c_it_t o0 = o_ij[l0], o1 = o_ij[l1], o2 = o_ij[l2];
            if (c0 == c1 && o0 < o2 && o1 < o2) {
                ++gakkari_count;
                break;
            }
            if (c1 == c2 && o1 < o0 && o2 < o0) {
                ++gakkari_count;
                break;
            }
            if (c2 == c0 && o2 < o1 && o0 < o1) {
                ++gakkari_count;
                break;
            }
        }
    } while (next_permutation(o_ij.begin(), o_ij.end()));
    constexpr long double all_count = 362880.0L;

    cout << setprecision(20) << (all_count - gakkari_count) / all_count << '\n';

    return 0;
}
