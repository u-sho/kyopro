#include <bits/stdc++.h>

struct UnionFind {
  std::vector<int> data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) std::swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
    using namespace std;
    int n,m,k;
    cin >> n >> m >> k;
    int kankei[n+1][n+1];
    fill(kankei[0],kankei[n+1],0);

    UnionFind uf(n);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a, b;
        uf.unite(a,b);
        kankei[a][b]=1;
        kankei[b][a]=1;
    }
    int ans[n];
    for(int i=0; i<k; i++){
        int c,d;
        cin>>c>>d;
        kankei[c][d]=-1;
        kankei[d][c]=-1;
    }




    return 0;
}
