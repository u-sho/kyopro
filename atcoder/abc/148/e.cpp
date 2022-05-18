#include <cmath>
#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long; // c++11

long long solve(long long n){
  if(n<5) return 0LL;
  if(n%2==1)return 0LL;

  // n, n-2, n-4, ... , 2
  ll ans = 0LL;
  // vector<ll> fives;
  // fives[0]=5LL;
  // for(int i=0; fives[i]<=n; i++){
  //   fives[i+1] = fives[i]*5LL; // 5, 25, 125, 525, ...
  // }
  ll five = 5LL;
  while(five*2LL <= n){
    ans += n/(five*2LL);
    five *= 5LL;
  }
  return ans;
}

int main(){
  ll n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}