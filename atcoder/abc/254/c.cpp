#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ui N, K;
  cin >> N >> K;
  vector<ui> a(N);
  for (ui &ai : a) cin >> ai;

  vector<vector<ui>> b(K);
  for (ui i = 0; i < K; i++) {       // O(N)
    for (ui j = i; j < N; j += K) {  // O(N/K)
      b[i].push_back(a[j]);
    }
  }

  for (auto &bi : b) sort(bi.begin(), bi.end());  // O(K N/K log N/K)

  for (ui i = 0; i < K; i++) {
    for (ui j = i, k = 0; j < N; j += K, k++) {
      a[j] = b[i][k];
    }
  }

  bool sorted = true;
  for (ui i = 1; i < N; i++) {
    if (a[i - 1] > a[i]) sorted = false;
  }

  cout << (sorted ? "Yes\n" : "No\n");

  return 0;
}
