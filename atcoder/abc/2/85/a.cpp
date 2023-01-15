#include <bits/stdc++.h>
using namespace std;

using ullong = unsigned long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  unsigned a, b;
  cin >> a >> b;

  bool ans = false;

  ans = ans || ((a == 1U) && (b == 2U || b == 3U));
  ans = ans || ((a == 2U) && (b == 4U || b == 5U));
  ans = ans || ((a == 3U) && (b == 6U || b == 7U));
  ans = ans || ((a == 4U) && (b == 8U || b == 9U));
  ans = ans || ((a == 5U) && (b == 10U || b == 11U));
  ans = ans || ((a == 6U) && (b == 12U || b == 13U));
  ans = ans || ((a == 7U) && (b == 14U || b == 15U));

  cout << (ans ? "Yes\n" : "No\n");

  return 0;
}
