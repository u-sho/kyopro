#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ui Q, query, x, c;  // 1<= Q <= 2e5
  cin >> Q;

  map<ui, ui> S;

  while (Q--) {
    cin >> query;
    if (query == 1) {
      cin >> x;
      map<ui, ui>::iterator it = S.find(x);
      if (it != S.end()) {
        (it->second)++;
      } else {
        S[x] = 1U;
      }
      continue;
    }

    if (query == 2) {
      cin >> x >> c;
      map<ui, ui>::iterator it2 = S.find(x);
      if (it2 != S.end()) continue;

      ui Sx = it2->second;
      if (Sx - min(c, Sx)) {
        it2->second = Sx - min(c, Sx);
        continue;
      }

      S.erase(it2);
      continue;
    }

    if (query == 3) {
      cout << S.rbegin()->first - S.begin()->first << '\n';
    }
  }

  return 0;
}
