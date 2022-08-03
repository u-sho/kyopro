#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iostream>

long long lcm(long long a, long long b){
  long long x = a*b;
  if(a<b){
    long long t=a;
    a=b;
    b=t;
  }
  long long r=a%b;
  for(long long r=a%b; r; r=a%b){
    a=b;
    b=r;
  }
  return x/b;
}

int main(){
  long long a, b, x;
  std::cin >> a >> b;
  x = a*b;
  std::cout << lcm(a,b) << std::endl;
  return 0;
}