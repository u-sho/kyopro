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
    vector<pair<pair<ui, ui>, ui>> uvw(N - 1u);
    for (pair<pair<ui, ui>, ui> &uvwi : uvw)
        cin >> uvwi.first.first >> uvwi.first.second >> uvwi.second;

    // t[from] = vector< { to, weight } >
    vector<vector<pair<ui, ui>>> t(N + 1U);
    for (const auto &uvwi : uvw) {
        ui u = uvwi.first.first;
        ui v = uvwi.first.second;
        ui w = uvwi.second;
        t[u].push_back({v, w});
        t[v].push_back({u, w});
    }

    sort(uvw.begin(), uvw.end(),
         [](auto a, auto b) { return a.second < b.second; });

        return 0;
}
