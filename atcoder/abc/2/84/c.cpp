#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    std::vector<unsigned> parent;

   public:
    UnionFind(unsigned n) : parent(n) {
        for (unsigned i = 0; i < n; i++) parent[i] = i;
    }

    unsigned root(unsigned x) {  // データx が属する木の根
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    bool merge(unsigned x, unsigned y) {  // 木x と 木y を併合
        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y) return false;
        parent[root_x] = root_y;
        return true;
    }

    bool same(int x, int y) {  // データx, y が属する木は同じか
        return root(x) == root(y);
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    UnionFind uf(102);
    unsigned N, M, u, v;
    cin >> N >> M;
    while (M--) {
        cin >> u >> v;
        if (uf.merge(u, v)) --N;
    }
    cout << N << '\n';

    return 0;
}
