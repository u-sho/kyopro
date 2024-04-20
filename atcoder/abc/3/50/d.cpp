#include <bits/stdc++.h>
using namespace std;

template <class Node>
class UnionFind {
    std::vector<Node> parent;

  public:
    std::vector<Node> friend_size;
    std::vector<Node> node_size;

    /* サイズ n の素集合を作成 */
    UnionFind(const std::size_t &n)
        : parent(n), friend_size(n, 0), node_size(n, 1) {
        for (std::size_t i = 0; i < n; i++) parent[i] = Node(i);
    }

    /* ノード x が属する木の根を返す */
    [[nodiscard]] Node root(const Node &x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    /* 木x と 木y を併合し成功したかを返す */
    bool merge(const Node &x, const Node &y) {
        unsigned root_x = root(x);
        unsigned root_y = root(y);
        friend_size[root_x]++;
        if (root_x == root_y) return false;
        // friend_size[root_y]++;
        if (node_size[root_x] > node_size[root_y]) swap(root_x, root_y);
        parent[root_x]       = root_y;
        node_size[root_y]   += node_size[root_x];
        friend_size[root_y] += friend_size[root_x];
        return true;
    }

    /* ノード x, y が属する木は同じか */
    [[nodiscard]] bool same(const Node &x, const Node &y) {
        return root(x) == root(y);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M;
    cin >> N >> M;
    vector<pair<uint, uint>> AB(M);
    for (pair<uint, uint> &ABi : AB) cin >> ABi.first >> ABi.second;

    UnionFind<uint> uf(N);
    for (const auto &ABi : AB) {
        uf.merge(ABi.first - 1, ABi.second - 1);

        for (uint i = 0; i < N; i++) {
            cout << uf.friend_size.at(i) << ' ';
        }
        cout << '\n';
    }

    // 正n角形の対角線の本数: n(n-3)/2
    // 正n角形の対角線と辺の本数: n(n-1)/2
    uint p0      = uf.root(0);
    uint64_t n   = uf.node_size[p0];
    uint64_t f   = uf.friend_size[p0];
    uint64_t ans = (n * (n - 1ULL) / 2ULL) - f;

    for (uint i = 1; i < N; i++) {
        const uint pi = uf.root(i);
        if (p0 == pi) continue;
        n    = uf.node_size[pi];
        f    = uf.friend_size[pi];
        ans += (n * (n - 1ULL) / 2ULL) - f;
        uf.merge(0, i);
        p0 = uf.root(0);
    }

    cout << ans << '\n';
    return 0;
}
