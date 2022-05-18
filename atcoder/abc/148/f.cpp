#include <cmath>
#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long; // c++11

struct hen {
  int a;
  int b;
  hen(int a, int b):a(a),b(b){}
};
vector<hen> ab;

ll solve(int u, int v){
  ll ans = 0LL;
  if(u==v)return ans;

  // 高橋君が移動する
  int k;
  u = k;

  if(u==v)return ans;

  // 青木君が移動する
  v = k;
  ans++;

  return solve(u, v);
}

int main(){
  int n, u, v;
  cin >> n >> u >> v;
  for(int i=1; i<n; i++){
    int _a, _b;
    cin >> _a >> _b;
    ab[i-1] = {_a,_b};
  }


  return 0;
}