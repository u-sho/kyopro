#include <bits/stdc++.h>

/* std::pair の入力 */
template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
};

/* 重複要素を削除する */
template <class Container>
void deduplicate(Container &v) {
    std::sort(begin(v), end(v));
    v.erase(std::unique(begin(v), end(v)), end(v));
    return;
}

using Node = unsigned;
using Path = std::pair<Node, Node>;

/* Union Find Tree */
class UnionFind {
    std::vector<Node> parent;

  public:
    /* サイズ n の素集合を作成: o(n) */
    UnionFind(const std::size_t &n) : parent(n) {
        for (std::size_t i = 0; i < n; i++) parent[i] = Node(i);
    }

    /* ノード x が属する木の根を返す：𝑶(log n) */
    [[nodiscard]] Node root(const Node x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    /* 小さい方を親として，木x と 木y を併合し成功したかを返す：𝑶(log n) */
    bool merge(const Path &xy) {
        unsigned root_x = root(xy.first);
        unsigned root_y = root(xy.second);
        if (root_x == root_y) return false;
        parent[std::min(root_x, root_y)] = std::max(root_x, root_y);
        return true;
    }

    /* x, y が属する木は同じか：𝑶(log n) */
    bool same(const Path &xy) { return root(xy.first) == root(xy.second); }
};

int main() {  // 𝑶( (M + K) log N + K log K) + o(Q lb Q)
    using namespace std;

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // 入力 --------------------------------------------------------
    unsigned N, M; /* N頂点M辺 */
    cin >> N >> M;

    UnionFind g(N + 1U);  // グラフ（素集合データ構造）
    for (unsigned i = 0; i < M; i++) {
        Path uv;
        cin >> uv;
        g.merge(uv);  // 𝑶(log N)
    }

    unsigned K; /* 非連結であるべきノード対の数 */
    cin >> K;

    vector<Path> xy(K); /* 非連結であるべきノード対 */
    for (Path &xyi : xy) cin >> xyi;

    unsigned Q; /* クエリ数 */
    cin >> Q;

    vector<Path> pq(Q); /* クエリ：連結するノード対 */
    for (Path &pqi : pq) cin >> pqi;

    // 前処理 ------------------------------------------------------

    // 非連結成分は代表元（根）でまとめる 𝑶(K log N)
    for (Path &xyi : xy) {
        Node root_xi = g.root(xyi.first);
        Node root_yi = g.root(xyi.second);
        xyi          = {min(root_xi, root_yi), max(root_xi, root_yi)};
    }
    deduplicate(xy);  // 重複を取り除きソートして管理 𝜣(K log K)

    // クエリも代表元（根）でまとめる 𝑶(Q log N)
    for (Path &pqi : pq) {
        Node root_pi = g.root(pqi.first);
        Node root_qi = g.root(pqi.second);
        pqi          = {min(root_pi, root_qi), max(root_pi, root_qi)};
    }

    // 判定 --------------------------------------------------------
    for (const Path &pqi : pq) {
        // 非連結であるべきか lb Q + O(1)
        if (binary_search(xy.begin(), xy.end(), pqi)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
