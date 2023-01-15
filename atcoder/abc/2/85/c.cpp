#include <iostream>
#include <string>
using namespace std;

using ullong = unsigned long long;

[[nodiscard]] ullong ullpow(const ullong e, const unsigned p) {
  ullong ret = 1U;
  for (unsigned i = 1U; i <= p; i++) ret *= e;

  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  ullong ans = 0ULL;
  for (unsigned i = 0U; i < S.length(); i++) {
    ans +=
        (S[i] - 'A' + 1ULL) * ullpow(('Z' - 'A' + 1ULL), (S.length() - i - 1U));
  }
  cout << ans << '\n';

  return 0;
}