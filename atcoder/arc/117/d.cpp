#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

using Tree = vector<vector<int>>;

// idx から１番遠いところを返す
pair<int, int> dfs(const Tree &g, vector<int> &measured, const int idx,
                   const int dist = 0) {
    measured[idx]      = dist;
    pair<int, int> ret = make_pair(dist, idx);
    for (const int e : g[idx]) {
        if (measured[e] != INT_MAX) continue;
        auto res = dfs(g, measured, e, dist + 1);
        if (res.first > ret.first) ret = res;
    }
    return ret;
}

int get_center(const Tree &g, vector<int> &measured, const int idx,
               const int half_diameter) {
    if (measured[idx] == half_diameter) return idx;
    for (const int e : g[idx]) {
        if (measured[e] < measured[idx]) continue;
        int res = get_center(g, measured, e, half_diameter);
        if (res != -1) return res;
    }
    return -1;
}

void calc_E(const Tree &g, vector<int> &E, const int idx, const int dist = 1) {
    E[idx] = dist;
    for (const int e : g[idx]) {
        if (E[e] != INT_MAX) continue;
        calc_E(g, E, e, dist + 1);
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    /* How to solve
     *   木の中心を根とする
     *   根の深さを 1 として、E_i を根からの距離と対応させるとよい
     */
    int N;
    cin >> N;

    Tree T(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        T[A - 1].push_back(B - 1);
        T[B - 1].push_back(A - 1);
    }

    // 0->最遠ノードd
    vector<int> dist_from_0(N, INT_MAX);
    auto ret = dfs(T, dist_from_0, 0);
    // d->最遠ノードd2
    int d = ret.second;
    vector<int> dist_from_d(N, INT_MAX);
    auto ret2 = dfs(T, dist_from_d, d);

    int tree_diameter = ret2.first;
    int center        = get_center(T, dist_from_d, d, tree_diameter / 2);

    vector<int> E(N, INT_MAX);
    calc_E(T, E, center);
    for (int i = 0; i < N - 1; i++) cout << E[i] << ' ';
    cout << E[N - 1] << endl;

    return 0;
}
