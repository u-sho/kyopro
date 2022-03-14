#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ui N;
  cin >> N;
  string S;
  cin >> S;

  if (N == 1U) {
    cout << S << '\n';
    return 0;
  }

  for (ui i = 0; i < N - 1U; i++) {
    if (S.at(i) == 'B') {
      if (S.at(i + 1U) == 'A') {
        cout << 'A';
        S.at(i) = 'A';
        S.at(i + 1U) = 'B';
      } else if (S.at(i + 1U) == 'B') {
        S.at(i + 1U) = 'A';
      } else {
        cout << 'B';
      }
    } else {
      cout << S.at(i);
    }
  }

  cout << S.at(N - 1U) << '\n';

  return 0;
}
