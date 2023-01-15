#include <iostream>
#include <map>
#include <string>
using namespace std;

using ullong = unsigned long long;

class UnionFind {
  map<const string, string> parent;

public:
  bool _exist(const string& x) { return (parent.find(x) != parent.end()); }
  void addNode(const string& x) {
    if (!_exist(x)) parent.insert(make_pair(x, x));
    return;
  }

  string root(const string& x) {  // データx が属する木の根
    if (parent[x] == x) return x;
    return parent[x] = root(parent[x]);
  }

  bool merge(const string& x, const string& y) {  // 木x と 木y を併合
    const string root_x = root(x);
    const string root_y = root(y);
    if (root_x == root_y) return false;
    if (root_x.length() < root_y.length()) parent[root_x] = root_y;
    else parent[root_y] = root_x;
    return true;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  UnionFind uf;
  bool ans = true;

  while (N--) {
    string S, T;
    cin >> S >> T;

    if (!ans) continue;

    uf.addNode(S);
    uf.addNode(T);
    if (!uf.merge(S, T)) ans = false;
  }

  cout << (ans ? "Yes\n" : "No\n");

  return 0;
}
