#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;

#define REP(i, n) for (ui i = 0U; i < (n); i++)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ui H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (string &Si : S) cin >> Si;

  int fi = INT32_MAX, fj, si, sj;
  REP(i, H) {
    REP(j, W) {
      if (S[i][j] == 'o') {
        if (fi == INT32_MAX) {
          fi = i;
          fj = j;
        } else {
          si = i;
          sj = j;
          break;
        }
      }
    }
  }

  cout << abs(si - fi) + abs(sj - fj) << '\n';
  return 0;
}
