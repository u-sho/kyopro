#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  unsigned N;
  cin >> N;
  string S;
  cin >> S;

  unsigned box_has_ball = 1u;
  unsigned counter = 0u;
  for (const auto Si : S) {
    if (Si == 'L') box_has_ball = max(1u, box_has_ball - 1u);
    if (Si == 'R') box_has_ball = min(3u, box_has_ball + 1u);
    if (box_has_ball == 3u) ++counter;
  }

  cout << counter << '\n';
  return 0;
}
