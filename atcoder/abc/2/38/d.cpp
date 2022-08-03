#include <iostream>

using namespace std;
using ui = unsigned;
using ulli = unsigned long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ui T;
  cin >> T;
  while (T--) {
    ulli a, s;
    cin >> a >> s;

    bool ans = false;
    ulli x = a;
    if (x <= (s >> 1ULL)) {
      ulli y = s - x;
      if ((x & y) == a) ans = true;
    }

    cout << (ans ? "Yes\n" : "No\n");
  }

  return 0;
}
