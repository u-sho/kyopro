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

  for (ui i = 0; i < N - K; i++) {
    if (a[i] > a[i + K]) swap(a[i], a[i + K]);
  }

  bool sorted = true;
  for (ui i = 1; i < N; i++) {
    if (a[i - 1] > a[i]) sorted = false;
  }

  cout << (sorted ? "Yes\n" : "No\n");

  return 0;
}
