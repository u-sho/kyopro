#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using modint = atcoder::modint998244353;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint N;
  cin >> N;
  vector<uint> a(N), b(N);
  for (uint &ai : a) cin >> ai;
  for (uint &bi : b) cin >> bi;

  if (N == 1) {
    cout << b[0] - a[0] + 1U << '\n';
    return 0;
  }

  vector<modint> p_sum(3003U, modint(0));
  for (uint j = a[0]; j < 3003U; j++) {
    if (j <= b[0]) p_sum[j] = modint(1);
    if (j == 0U) continue;
    p_sum[j] += p_sum[j - 1U];
  }

  for (uint i = 1U; i < N; i++) {
    for (uint j = a[i] + 1U; j < 3003U; j++) {
      if (j <= b[i])
        p_sum[j] += p_sum[j - 1U];
      else
        p_sum[j] = p_sum[j - 1U];
    }
  }

  cout << p_sum[3000U].val() << '\n';

  return 0;
}
