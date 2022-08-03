#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using ulli = unsigned long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ulli N, A, B;
  cin >> N >> A >> B;

  ulli sum1toN = N * (N + 1ULL) / 2ULL;
  ulli sumAmulti = A * (N / A) * (N / A + 1ULL) / 2ULL;
  ulli sumBmulti = B * (N / B) * (N / B + 1ULL) / 2ULL;
  ulli lcmAB = lcm(A, B);
  ulli sumLcmABmulti = lcmAB * (N / lcmAB) * (N / lcmAB + 1ULL) / 2ULL;

  cout << sum1toN - sumAmulti - sumBmulti + sumLcmABmulti << '\n';

  return 0;
}
