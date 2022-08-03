#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  vector<bool> a(360, false);
  a.at(0) = true;

  unsigned N;
  cin >> N;
  vector<unsigned> A(N);
  for (unsigned &Ai : A) cin >> Ai;

  unsigned i = 0;
  for (const unsigned Ai : A) {
    i = (i + Ai) % 360;
    a[i] = true;
  }

  unsigned left = 0, ans = 0;
  for (unsigned i = 0; i < 360; i++) {
    if (a[i]) {
      ans = max(ans, i - left);
      left = i;
    }
  }
  ans = max(ans, 360 - left);

  cout << ans << '\n';

  return 0;
}
