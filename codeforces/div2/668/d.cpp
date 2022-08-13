#include <bits/stdc++.h>
using namespace std;

// i edit https://ei1333.github.io/luzhiled/snippets/graph/template.html
template <typename T>
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T> >;
template <typename T>
using WeightedGraph = vector<Edges<T> >;

// https://ei1333.github.io/luzhiled/snippets/tree/tree-diameter.html
// from here --------------------------------------------------------
template <typename T>
pair<T, int> dfs(const WeightedGraph<T> &g, int idx, int par) {
    pair<T, int> ret(0, idx);
    for (auto &e : g[idx]) {
        if (e.to == par) continue;
        auto cost = dfs(g, e.to, idx);
        cost.first += e.cost;
        ret = max(ret, cost);
    }
    return ret;
}

template <typename T>
T tree_diameter(const WeightedGraph<T> &g) {
    auto p = dfs(g, 0, -1);
    auto q = dfs(g, p.second, -1);
    return (q.first);
}
// to here -----------------------------------------------------------

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, da, db;
        cin >> a >> a >> b >> da >> db;
        WeightedGraph<int> g(n);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v, 1);
            g[v].emplace_back(u, 1);
        }
        if (da <= db)
            cout << "Bob\n";
        else if ((tree_diameter(g) + 1) / 2 <= db)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }

    return 0;
}
