// 𝑶((H+W)Q): 行の置換と列の置換を更新，最後にindexing

#include <bits/stdc++.h>

int main() {
  using namespace std;

  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  unsigned H, W;
  cin >> H >> W;

  vector<string> A;
  for (unsigned i = 0U; i < H; i++) {
    string Ai;
    cin >> Ai;
    A.push_back(Ai);
  }

  vector<unsigned> h_index, w_index;
  for (unsigned i = 0U; i < H; i++) h_index.push_back(i);
  for (unsigned i = 0U; i < W; i++) w_index.push_back(i);

  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;

    for (int hi = 0; hi < a / 2; hi++) {
      swap(h_index[hi], h_index[a - 1 - hi]);
    }
    for (int hi = 0; hi < ((int)H - a) / 2; hi++) {
      swap(h_index[(int)H - hi - 1], h_index[a + hi]);
    }
    for (int wi = 0; wi < b / 2; wi++) {
      swap(w_index[wi], w_index[b - 1 - wi]);
    }
    for (int wi = 0; wi < ((int)W - b) / 2; wi++) {
      swap(w_index[(int)W - wi - 1], w_index[b + wi]);
    }
  }

  for (unsigned i = 0U; i < H; i++) {
    for (unsigned j = 0; j < W; j++) {
      cout << A[h_index[i]][w_index[j]];
    }
    cout << '\n';
  }
  return 0;
}