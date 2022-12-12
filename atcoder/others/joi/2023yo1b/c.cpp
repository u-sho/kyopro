#include <iostream>
#include <string>

using namespace std;

int main(){
  unsigned N;
  cin >> N;
  string S;
  cin >> S;

  if (S.substr(0u, N/2u) == S.substr(N/2u, N/2u)) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
