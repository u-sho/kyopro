#include <cmath>
#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iostream>
#include <algorithm>

using namespace std;
const long long MOD = 1000000007;

int main(){
  int n;
  cin >>n;
  vector<long long> a;
  for(int i=0; i<n; i++){
    long long _a;
    cin >> _a;
    a.push_back(_a);
  }
  vector<long long> raps(n);
  partial_sum(a.rbegin(),a.rend(),raps.begin());

  long long sum = 0ll;
  for(int i=0; i<n-1; i++){
    sum += a[0] ^ raps[n-2-i];
    sum %= MOD;
  }
  cout << sum << endl;
  return 0;
}
