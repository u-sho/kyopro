#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ui N;
  cin >> N;

  vector<ui> Aim1;
  for (ui i = 0; i < N; ++i) {
    vector<ui> Ai(i + 1);
    for (ui j = 0; j < Ai.size(); j++) {
      if (j == 0 || j == i)
        Ai.at(j) = 1;
      else
        Ai.at(j) = Aim1[j - 1] + Aim1[j];

      cout << Ai[j] << (j == i ? "\n" : " ");
    }
    Aim1 = Ai;
  }

  return 0;
}