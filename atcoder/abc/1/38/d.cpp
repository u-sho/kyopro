#include <iostream>
#include <vector>
constexpr std::size_t N_MAX = 200'005UL;  //'

using std::vector;
// 辺の集合
using Graph = vector<vector<int>>;

vector<bool> visited(N_MAX);
vector<long> node(N_MAX);

void dfs(const Graph &g, const std::size_t &s = 1UL, long sum = 0L) {
    visited.at(s) = true;

    // ここで計算
    node.at(s) += sum;

    for (const int &next : g.at(s)) {
        if (visited.at(next)) continue;
        dfs(g, next, node.at(s));
    }
    return;
};

int main(void) {
    using std::cin;
    using std::cout;
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Graph tree(n + 1UL);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
    }

    for (int i = 1; i <= q; ++i) {
        long p, x;
        cin >> p >> x;
        node.at(p) += x;
    }

    dfs(tree);
    for (int i = 1; i <= n; ++i) {
        cout << node.at(i) << (i == n ? '\n' : ' ');
    }

    return 0;
}