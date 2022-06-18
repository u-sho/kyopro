#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui N;
    cin >> N;
    vector<pair<ui, ui>> LR(N);
    for (pair<ui, ui> &LRi : LR) cin >> LRi.first >> LRi.second;

    SORT(LR);
    vector<pair<ui, ui>> answer;
    answer.push_back(LR[0]);
    REP1(i, N) {
        ui ansR = answer.back().second;
        if (LR[i].first <= ansR) {
            answer.back().second = max(LR[i].second, ansR);
            continue;
        }
        answer.push_back(LR[i]);
    }

    for (pair<ui, ui> &LRi : answer) {
        cout << LRi.first << " " << LRi.second << "\n";
    }

    return 0;
}
