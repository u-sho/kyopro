#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui N;
    cin >> N;
    vector<vector<int>> C(N), trans_C(N);
    for (auto &Ci : C) {
        Ci.resize(N);
        REP(j, N) {
            cin >> Ci[j];
            trans_C.at(j).push_back(Ci[j]);
        }
    }

    // No 判定
    // 各行ベクトルの階差数列がすべて等しい
    // 各列ベクトルの階差数列がすべて等しい
    vector<int> C0_dif(N), trans_C0_dif(N);
    adjacent_difference(ALL(C.at(0)), C0_dif.begin());
    adjacent_difference(ALL(trans_C.at(0)), trans_C0_dif.begin());
    REP(i, N) {
        vector<int> Ci_dif(N), trans_Ci_dif(N);
        adjacent_difference(ALL(C.at(i)), Ci_dif.begin());
        adjacent_difference(ALL(trans_C.at(i)), trans_Ci_dif.begin());
        if (C0_dif != Ci_dif || trans_C0_dif != trans_Ci_dif) {
            cout << "No\n";
            return 0;
        }
    }

    int min_C = accumulate(ALL(C), INT_MAX, [](int acc, auto Ci) {
        return min(acc, *min_element(ALL(Ci)));
    });

    return 0;
}
