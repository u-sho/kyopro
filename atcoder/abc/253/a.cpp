#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  vector<ui> abc(3);
  for (ui &abci : abc) cin >> abci;
  ui b = abc[1];
  SORT(abc);
  if (b == abc[1]) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
