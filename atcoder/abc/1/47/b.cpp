#include <cmath>
#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string S;
  cin >> S;
  int count = 0;
  int rs = S.size();
  for(int i=0; i<rs/2; i++){
    if (S[i]!=S[rs-i-1])count++;
  }
  cout << count << endl;
    return 0;
}