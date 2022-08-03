#include <iostream>

using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

constexpr ulli mod = 998'244'353ULL;   //'
constexpr ulli div2 = 499'122'177ULL;  //'

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ulli N;
  cin >> N;

  ulli ans = 0ULL;
  ulli ten = 1ULL;
  for (ulli i = 1ULL; i <= 18ULL; i++) {
    if (N < ten * 10ULL) {
      ulli sub = (N - ten) % mod;
      ans += ((sub + 1ULL) * (sub + 2ULL) % mod) * div2 % mod;
      cout << (ans % mod) << '\n';
      return 0;
    }
    ulli nine = (ten * 9ULL) % mod;
    ans += (((nine * nine % mod) + nine) % mod) * div2 % mod;
    ans %= mod;
    ten *= 10ULL;
  }
  ulli sub2 = (N - 1'000'000'000'000'000'000ULL) % mod;
  ans += ((sub2 + 1ULL) * (sub2 + 2ULL) % mod) * div2 % mod;
  cout << (ans % mod) << '\n';
  return 0;
}
