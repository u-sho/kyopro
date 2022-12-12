#include <iostream>
#include <vector>

int main() {
  using namespace std;

  unsigned N; cin >> N;
  vector<unsigned> A(N); for (unsigned &Ai : A) cin >> Ai;
  unsigned M; cin >> M;
  vector<bool> B(1024u, false);
  for (unsigned Bi, i=0u; i<M; i++) {
    cin >> Bi;
    B.at(Bi) = true;
  }

  unsigned score = 0u;
  for (const unsigned Ai : A) {
    score += Ai;
    if (B.at(score)) score = 0u;
  }

  cout << score << '\n';
  return 0;
}
