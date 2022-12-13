#include <iostream>
#include <vector>

using namespace std;

using Cards = vector<unsigned>;

unsigned n;

void kcut(const unsigned k, Cards &cards) {
  Cards cut;
  cut.assign(cards.begin()+k, cards.end());
  for (unsigned i = 0u; i < k; i++) {
    cut.push_back(cards.at(i));
  }
  cards.assign(cut.begin(), cut.end());
  return;
}

void riffle_shuffle(Cards &cards) {
  Cards shuffled;
  for (unsigned i = 0u; i < n; i++) {
    shuffled.push_back(cards.at(i));
    shuffled.push_back(cards.at(n+i));
  }
  cards.assign(shuffled.begin(), shuffled.end());
  return;
}

int main(){
  cin >> n;
  Cards cards;
  for (unsigned i = 1u; i <= 2u*n; i++) cards.push_back(i);

  unsigned m;
  cin >> m;

  while(m--) {
    unsigned k;
    cin >> k;
    if (k == 0u) riffle_shuffle(cards);
    else kcut(k, cards);
  }

  for (const unsigned card : cards) cout << card << '\n';

  return 0;
}

