#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  unsigned N;
  cin >> N;

  unsigned ans = 110'000'000U;
  --N;
  ans += (N % 10U) * 10U;  // 6
  N   /= 10U;
  ans += (N % 10U) * 101U;  // 5z
  N   /= 10U;
  ans += (N % 10U) * 11000U;  // 4y
  N   /= 10U;
  ans += (N % 10U) * 100000U;  // 3
  N   /= 10U;
  ans += (N % 10U) * 1'000'000;  // 2
  N   /= 10U;
  ans += (N % 10U) * 110'000'000U;
  // 1x2'34y'56z

  cout << ans << '\n';

  return 0;
}
