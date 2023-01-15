#include <bits/stdc++.h>
using namespace std;

#define REP1(i, n) for (unsigned i = 1U; i <= (n); i++)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  unsigned N;
  cin >> N;
  string S;
  cin >> S;

  S = " " + S;

  REP1(i, N) {
    unsigned l = 0U;
    REP1(k, N - i) {
      if (S[k] != S[k + i]) l = k;
      else break;
    }
    cout << l << '\n';
  }

  return 0;
}
