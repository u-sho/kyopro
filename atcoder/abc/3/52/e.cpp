#include <bits/stdc++.h>

// マージの工夫をしていないため，クエリは 𝑶(log n)

template <class Node, class EdgeCost>
class UnionFind {
    std::vector<Node> parent;

  public:
    std::vector<EdgeCost> costs;

    /* サイズ n の素集合を作成: o(n) */
    UnionFind(const std::size_t &n) : parent(n) {
        for (std::size_t i = 0; i < n; i++) parent[i] = Node(i);
        costs.assign(n, EdgeCost(0));
    }

    /* ノード x が属する木の根を返す：𝑶(log n) */
    [[nodiscard]] Node root(const Node &x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    /* 木x と 木y を併合し成功したかを返す：𝑶(log n) */
    bool merge(const Node &x, const Node &y, const EdgeCost &c) {
        unsigned root_x = root(x);
        unsigned root_y = root(y);
        if (root_x == root_y) return false;
        if (costs[root_x] > costs[root_y]) std::swap(root_x, root_y);
        parent[root_x]  = root_y;
        costs[root_y]  += costs[root_x] + c;
        return true;
    }

    /* ノード x, y が属する木は同じか：𝑶(log n) */
    [[nodiscard]] bool same(const Node &x, const Node &y) {
        return root(x) == root(y);
    }
};

int main() {
    using namespace std;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // Ci でソートして小さい順にufに突っ込むと最小全域木になる
    uint N, M;
    cin >> N >> M;
    vector<vector<uint>> A(M);
    for (uint i = 0; i < M; i++) {
        uint Ki, Ci;
        cin >> Ki >> Ci;
        A[i].resize(Ki);
        for (uint &Aij : A[i]) cin >> Aij;
        // ソート用にCiを付加しておく
        A[i].push_back(Ci);
    }

    // Ci でソート
    sort(A.begin(), A.end(),
         [](auto const &x, auto const &y) { return x.back() < y.back(); });

    UnionFind<uint, uint64_t> uf(N);
    for (const auto &Si : A) {
        const uint Ki = Si.size() - 1U;
        const uint Ci = Si.back();
        for (uint j = 1; j < Ki; j++) {
            uf.merge(Si[0] - 1U, Si[j] - 1U, uint64_t(Ci));
        }
    }

    // 連結判定
    bool isConnected = true;
    for (uint i = 1; i < N; i++) {
        if (!uf.same(0, i)) isConnected = false;
    }

    if (!isConnected) {
        cout << "-1\n";
        return 0;
    }

    cout << uf.costs[uf.root(0U)] << '\n';
    return 0;
}