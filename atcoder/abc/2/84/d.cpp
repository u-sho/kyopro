#include <iostream>
using namespace std;

using ullong = unsigned long long;

[[nodiscard]] ullong ullsqrt(const ullong &n) {
  ullong low = 2ULL, high = 1ULL << 31;
  while (low < high) {
    ullong mid = (low + high) / 2;
    if (mid * mid <= n && n < (mid + 1ULL) * (mid + 1ULL)) return mid;
    if (mid * mid < n)
      low = mid;
    else
      high = mid;
  }
  return low;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  unsigned T;
  cin >> T;
  while (T--) {
    ullong N, p, q;
    cin >> N;
    if (N % 2ULL == 0ULL)
      p = 2ULL;
    else
      for (p = 3ULL; N % p; p += 2ULL)
        ;
    N /= p;
    if (N % p == 0ULL)
      q = N / p;
    else {
      q = p;
      p = ullsqrt(N);
    }
    cout << p << ' ' << q << '\n';
  }

  return 0;
}
