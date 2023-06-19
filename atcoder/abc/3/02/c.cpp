#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

#define REP(i, n) for (unsigned i = 0; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (string& Si : S) cin >> Si;

    // for next_permutation
    sort(ALL(S));

    do {
        /* 条件を満たしているか */
        bool is_satisfied = true;
        REP(i, N - 1) {
            unsigned diff_counter = 0;
            REP(j, M) { diff_counter += (S[i][j] != S[i + 1][j]); }
            if (diff_counter > 1U) {
                is_satisfied = false;
                break;
            }
        }
        if (is_satisfied) {
            cout << "Yes\n";
            return 0;
        }
    } while (next_permutation(ALL(S)));

    cout << "No\n";

    return 0;
}
