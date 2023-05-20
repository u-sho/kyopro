#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (string& Si : S) {
        cin >> Si;
        SORT(Si);
        Si.push_back(Si.front());  // XXX: 1つshiftして数える用
    }

    // diff_S[i][j]: S[i] と S[j] が何文字違うのか数える．
    vector<vector<unsigned>> diff_S(N, vector<unsigned>(N, 0));
    REP(i, N) {
        REP(j, N) {
            unsigned diff_counter         = 0;
            unsigned diff_counter_shift_l = 0;
            unsigned diff_counter_shift_r = 0;
            REP(k, M) {
                diff_counter         += (S[i][k] != S[j][k]);
                diff_counter_shift_l += (S[i][k] != S[j][k + 1]);
                diff_counter_shift_r += (S[i][k + 1] != S[j][k]);
            }
            diff_S[i][j] = min(diff_counter,
                               min(diff_counter_shift_l, diff_counter_shift_r));
        }
    }

    return 0;
}
