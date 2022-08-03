#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  cout << ((n > 4 || n == 1) ? "Yes\n" : "No\n");

  return 0;
}
