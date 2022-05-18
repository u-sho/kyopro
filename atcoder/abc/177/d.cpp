#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
struct UnionFind {
    vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size;

    UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
        size.resize(N);
        for (int i = 0; i < N; i++) {
            par[i]  = i;
            size[i] = 1;
        }
    }

    int root(
        int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {  // xとyの木を併合
        int rx = root(x);       // xの根をrx
        int ry = root(y);       // yの根をry
        if (rx == ry) return;  // xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry;  // xとyの根が同じ時：xの根rxをyの根ryにつける
        // cout << x << ", " << rx << "), (" << y << ", " << ry << ")\n";
        size[ry] += size[rx];
        // cout << size[ry] << "\n";
    }

    bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind friends(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends.unite(a - 1, b - 1);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = max(friends.size[i], cnt);
    }

    cout << cnt << "\n";

    return 0;
}
