#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP1(i, n) for (int i = 1; i < (n); i++)

int ten_pow[6] = {1, 10, 100, 1'000, 10'000, 100'000};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int K;
    cin >> K;
    string S, T;
    cin >> S;
    cin >> T;

    vector<int> s(10UL, 0), t(10UL, 0);
    for (int i = 0; i < 4; i++) {
        s[S[i] - '0']++;
        t[T[i] - '0']++;
    }

    ulli pattern_num = 0ULL;
    ulli win_s_num   = 0ULL;
    REP1(i, 10) {  // S[4] == i のとき
        if (s[i] + t[i] + 1 > K) continue;

        REP1(j, 10) {  // T[4] == j のとき
            if (s[j] + t[j] + 1 + (i == j ? 1 : 0) > K) continue;

            pattern_num += lli(K - s[i] - t[i]) * lli(K - s[j] - t[j]);
            if (i == j) pattern_num -= (K - s[i] - t[i]);

            int s_point = 0, t_point = 0;
            ++s[i], ++t[j];
            REP1(k, 10) {
                s_point += k * ten_pow[s[k]];
                t_point += k * ten_pow[t[k]];
            }
            --s[i], --t[j];

            if (s_point > t_point) {
                win_s_num += lli(K - s[i] - t[i]) * lli(K - s[j] - t[j]);
                if (i == j) win_s_num -= (K - s[i] - t[i]);
            }
        }
    }

    cout << fixed << setprecision(8);
    cout << (long double)(win_s_num * 100000) /
                (long double)(pattern_num * 100000)
         << "\n";

    return 0;
}
