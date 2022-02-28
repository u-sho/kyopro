#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using lli = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  lli A, B, C;
  cin >> A >> B >> C;

  cout << pow_mod(A, pow_mod(B, C, 84), 10);

  return 0;
}
