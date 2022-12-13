#include <iostream>
#include <string>

using namespace std;

int main(){
  string code;
  cin >> code;

  for (const auto c : code) {
    cout << char(((c-'A'+23)%26)+'A');
  }
  cout << '\n';

  return 0;
}
