#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)

using Graph = vector<vector<size_t>>;

unsigned K = 0U;
set<size_t> visited;
void dfs(const Graph &G, const size_t v) {
  if (K > 1'000'000U) return;
  ++K;

  visited.insert(v);
  for (auto next_v : G[v]) {
    if (visited.count(next_v)) continue;
    dfs(G, next_v);
  }
  visited.erase(v);

  return;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  size_t N, M;
  cin >> N >> M;

  Graph g(N + 1UL);
  REP(i, M) {
    size_t u, v;
    cin >> u >> v;
    if (u == v) continue;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }

  dfs(g, 1UL);
  cout << min(K, 1'000'000U) << '\n';

  return 0;
}
