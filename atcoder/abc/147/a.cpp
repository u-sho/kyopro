#include <iostream>
#include <algorithm>

using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  string ans = (a+b+c >= 22) ? "bust\n" : "win\n";
  cout << ans;
    return 0;
}