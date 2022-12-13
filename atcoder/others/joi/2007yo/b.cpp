#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  using namespace std;

  vector<bool> participated(32u, false);
  for (unsigned i = 0u; i < 28u; i++) {
    unsigned student_number;
    cin >> student_number;
    participated.at(student_number) = true;
  }

  vector<unsigned> absents;
  for (unsigned i = 1u; i <= 30u; i++) {
    if (!participated.at(i)) absents.push_back(i);
  }

  cout << min(absents[0], absents[1]) << '\n';
  cout << max(absents[0], absents[1]) << '\n';
}
