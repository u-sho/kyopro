#include <bits/stdc++.h>
using namespace std;
// ei1333 thx
template< typename T >
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

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;

template< typename T >
vector< edge< T > > eulerian_path(Edges< T > es, int s, bool directed) {
  int V = 0;
  for(auto &e : es) V = max(V, max(e.to, e.src) + 1);
  vector< vector< pair< edge< T >, int > > > g(V);
  for(auto &e : es) {
    int sz_to = (int) g[e.to].size();
    g[e.src].emplace_back(e, sz_to);
    if(!directed) {
      int sz_src = (int) g[e.src].size() - 1;
      swap(e.src, e.to);
      g[e.src].emplace_back(e, sz_src);
    }
  }
  vector< edge< T > > ord;
  stack< pair< int, edge< T > > > st;
  st.emplace(s, edge< T >(-1, -1));
  while(st.size()) {
    int idx = st.top().first;
    if(g[idx].empty()) {
      ord.emplace_back(st.top().second);
      st.pop();
    } else {
      auto e = g[idx].back();
      g[idx].pop_back();
      if(e.second == -1) continue;
      if(!directed) g[e.first.to][e.second].second = -1;
      st.emplace(e.first.to, e.first);
    }
  }
  ord.pop_back();
  reverse(begin(ord), end(ord));
  if(ord.size() != es.size()) return {};
  return ord;
}

int main(){
    using namespace std;
    int n,m;
    cin >> n >> m;
    Edges<int> es;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        Edges<int> 
    }
    return 0;
}